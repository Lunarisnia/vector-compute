#pragma once
#include "VkBootstrap.h"
#include "engine/garbage_collector/garbage_collector.hpp"
#include "vk_mem_alloc.h"
#include <cstdint>
#include <vulkan/vulkan_core.h>
class Pandora {
private:
  GarbageCollector garbageCollector;
  vkb::Instance instance;
  vkb::Device device;
  VkPhysicalDevice choosenPhysicalDevice;

  VkQueue graphicsQueue;
  uint32_t graphicsQueueFamily;

  VmaAllocator allocator;

  VkDescriptorPool descriptorPool;
  VkDescriptorSetLayout descriptorSetLayout;
  VkDescriptorSet descriptorSet;

private:
  void initInstance();
  void initDescriptor();

public:
  void Init();

  void Cleanup();
};
