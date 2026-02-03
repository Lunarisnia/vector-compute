#include "engine/pandora/pandora.hpp"
#include "VkBootstrap.h"
#include "engine/vk_toolkit/vk_toolkit.hpp"
#include "fmt/base.h"
#include <vulkan/vulkan_core.h>

void Pandora::Init() {
  initInstance();
  initDescriptor();
}

void Pandora::Cleanup() { garbageCollector.Flush(); }

void Pandora::initInstance() {
  vkb::InstanceBuilder builder;

  vkb::Result<vkb::Instance> instanceRet = builder.use_default_debug_messenger()
                                               .request_validation_layers()
                                               .set_headless()
                                               .require_api_version(1, 3, 0)
                                               .build();
  if (!instanceRet) {
    fmt::println("{}", instanceRet.error().message());
    throw instanceRet.error();
  }
  instance = instanceRet.value();

  // vulkan 1.3 features
  VkPhysicalDeviceVulkan13Features features{
      .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES};
  // features.dynamicRendering = true;
  features.synchronization2 = true;

  // vulkan 1.2 features
  VkPhysicalDeviceVulkan12Features features12{
      .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES};
  features12.bufferDeviceAddress = true;
  features12.descriptorIndexing = true;

  vkb::PhysicalDeviceSelector selector{instance};
  vkb::PhysicalDevice physicalDevice = selector.set_minimum_version(1, 3)
                                           .set_required_features_13(features)
                                           .set_required_features_12(features12)
                                           .select()
                                           .value();

  vkb::DeviceBuilder deviceBuilder{physicalDevice};
  auto deviceBuilderRet = deviceBuilder.build();

  device = deviceBuilderRet.value();
  choosenPhysicalDevice = physicalDevice.physical_device;

  graphicsQueue = device.get_queue(vkb::QueueType::graphics).value();
  graphicsQueueFamily =
      device.get_queue_index(vkb::QueueType::graphics).value();

  VmaAllocatorCreateInfo allocatorInfo = {};
  allocatorInfo.physicalDevice = choosenPhysicalDevice;
  allocatorInfo.device = device;
  allocatorInfo.instance = instance;
  allocatorInfo.flags = VMA_ALLOCATOR_CREATE_BUFFER_DEVICE_ADDRESS_BIT;
  vmaCreateAllocator(&allocatorInfo, &allocator);

  garbageCollector.AddFunction([&]() { vmaDestroyAllocator(allocator); });
}

void Pandora::initDescriptor() {
  // Create Descriptor pool to store the input data
  VkDescriptorPoolSize poolSize = {VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 2};
  VkDescriptorPoolCreateInfo descriptorPoolCreateInfo =
      VKToolkit::DescriptorPoolCreateInfo(1, 1, &poolSize);
  vkCreateDescriptorPool(device, &descriptorPoolCreateInfo, nullptr,
                         &descriptorPool);
  garbageCollector.AddFunction(
      [&]() { vkDestroyDescriptorPool(device, descriptorPool, nullptr); });

  // Create the layout for storing the input in this case (a + b) input a and
  // input b
  VkDescriptorSetLayoutBinding binding = {0, VK_DESCRIPTOR_TYPE_STORAGE_BUFFER,
                                          2, VK_SHADER_STAGE_ALL, nullptr};
  VkDescriptorSetLayoutCreateInfo descriptorSetLayoutCreateInfo =
      VKToolkit::DescriptorSetLayoutCreateInfo(1, &binding);
  vkCreateDescriptorSetLayout(device, &descriptorSetLayoutCreateInfo, nullptr,
                              &descriptorSetLayout);
  garbageCollector.AddFunction([&]() {
    vkDestroyDescriptorSetLayout(device, descriptorSetLayout, nullptr);
  });

  // Allocate the layout to the pool
  VkDescriptorSetAllocateInfo allocateInfo =
      VKToolkit::DescriptorSetAllocateInfo(1, &descriptorSetLayout,
                                           descriptorPool);
  vkAllocateDescriptorSets(device, &allocateInfo, &descriptorSet);
}
