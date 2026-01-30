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
}

void Pandora::Cleanup() { garbageCollector.Flush(); }
