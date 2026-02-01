#include "engine/pandora/pandora.hpp"
#include "VkBootstrap.h"
#include "fmt/base.h"

void Pandora::Init() {
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

void Pandora::Cleanup() { garbageCollector.Flush(); }
