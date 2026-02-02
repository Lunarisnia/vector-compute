#pragma once

#include <vulkan/vulkan_core.h>
class VKToolkit {
public:
  static VkDescriptorPoolCreateInfo
  DescriptorPoolCreateInfo(int maxSets, int poolSizeCount,
                           VkDescriptorPoolSize poolSize, unsigned int flags);
};

// VkDescriptorPoolCreateInfo pool_info = {};
// pool_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
// pool_info.flags = 0;
// pool_info.maxSets = 1;
// pool_info.poolSizeCount = 1;
// pool_info.pPoolSizes = &pool_size;
// init.disp.createDescriptorPool(&pool_info, nullptr, &data.descriptor_pool);
