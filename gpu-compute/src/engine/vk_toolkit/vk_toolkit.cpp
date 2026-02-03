
#include "engine/vk_toolkit/vk_toolkit.hpp"
VkDescriptorPoolCreateInfo
VKToolkit::DescriptorPoolCreateInfo(int maxSets, int poolSizeCount,
                                    VkDescriptorPoolSize *poolSize,
                                    unsigned int flags) {
  VkDescriptorPoolCreateInfo poolCreateInfo = {};
  poolCreateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
  poolCreateInfo.flags = flags;
  poolCreateInfo.maxSets = maxSets;
  poolCreateInfo.poolSizeCount = poolSizeCount;
  poolCreateInfo.pPoolSizes = poolSize;
  return poolCreateInfo;
}

VkDescriptorSetLayoutCreateInfo
VKToolkit::DescriptorSetLayoutCreateInfo(int bindingCount,
                                         VkDescriptorSetLayoutBinding *binding,
                                         unsigned int flags) {
  VkDescriptorSetLayoutCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
  createInfo.flags = 0;
  createInfo.bindingCount = 1;
  createInfo.pBindings = binding;
  return createInfo;
}
