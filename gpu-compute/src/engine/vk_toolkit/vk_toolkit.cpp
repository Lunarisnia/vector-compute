
#include "engine/vk_toolkit/vk_toolkit.hpp"
#include <vulkan/vulkan_core.h>
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

VkDescriptorSetAllocateInfo
VKToolkit::DescriptorSetAllocateInfo(int descriptorSetCount,
                                     VkDescriptorSetLayout *descriptorSetLayout,
                                     VkDescriptorPool descriptorPool) {
  VkDescriptorSetAllocateInfo allocateInfo = {};
  allocateInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
  allocateInfo.descriptorPool = descriptorPool;
  allocateInfo.descriptorSetCount = descriptorSetCount;
  allocateInfo.pSetLayouts = descriptorSetLayout;
  return allocateInfo;
}
