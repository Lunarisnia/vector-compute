#pragma once

#include <vulkan/vulkan_core.h>
class VKToolkit {
public:
  static VkDescriptorPoolCreateInfo
  DescriptorPoolCreateInfo(int maxSets, int poolSizeCount,
                           VkDescriptorPoolSize *poolSize,
                           unsigned int flags = 0);
  static VkDescriptorSetLayoutCreateInfo
  DescriptorSetLayoutCreateInfo(int bindingCount,
                                VkDescriptorSetLayoutBinding *binding,
                                unsigned int flags = 0);
};
