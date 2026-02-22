
#include "engine/vk_toolkit/vk_toolkit.hpp"
#include <cstddef>
#include <cstdint>
#include <string>
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

VkShaderModuleCreateInfo
VKToolkit::ShaderModuleCreateInfo(std::vector<uint32_t> &codeBuffer,
                                  unsigned int flags) {
  uint32_t codeSize = codeBuffer.size() * sizeof(uint32_t);
  VkShaderModuleCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  createInfo.flags = flags;
  createInfo.pNext = nullptr;
  createInfo.codeSize = codeSize;
  createInfo.pCode = codeBuffer.data();
  return createInfo;
}

VkPipelineLayoutCreateInfo
VKToolkit::PipelineLayoutCreateInfo(VkDescriptorSetLayout *descriptorSetLayout,
                                    unsigned int flags) {
  VkPipelineLayoutCreateInfo createInfo = {};
  createInfo.flags = flags;
  createInfo.pNext = nullptr;
  createInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
  createInfo.pSetLayouts = descriptorSetLayout;
  createInfo.setLayoutCount = 1; // For now
  return createInfo;
}

VkPipelineShaderStageCreateInfo VKToolkit::PipelineShaderStageCreateInfo(
    VkShaderModule shaderModule, VkShaderStageFlagBits stage,
    const std::string &pName, unsigned int flags) {
  VkPipelineShaderStageCreateInfo stageInfo{};
  stageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
  stageInfo.pNext = nullptr;
  stageInfo.stage = stage;
  stageInfo.module = shaderModule;
  stageInfo.pName = pName.c_str();
  return stageInfo;
}

VkComputePipelineCreateInfo
VKToolkit::ComputePipelineCreateInfo(VkPipelineLayout pipelineLayout,
                                     VkPipelineShaderStageCreateInfo stage,
                                     unsigned int flags) {
  VkComputePipelineCreateInfo computePipelineCreateInfo = {};
  computePipelineCreateInfo.sType =
      VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
  computePipelineCreateInfo.pNext = nullptr;
  computePipelineCreateInfo.flags = flags;
  computePipelineCreateInfo.layout = pipelineLayout;
  computePipelineCreateInfo.stage = stage;
  return computePipelineCreateInfo;
}
