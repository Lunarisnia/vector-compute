#include "engine/pandora/pandora.hpp"
#include "VkBootstrap.h"

void Pandora::Init() {
  vkb::InstanceBuilder builder;

  vkb::Result<vkb::Instance> instance = builder.use_default_debug_messenger()
                                            .request_validation_layers()
                                            .set_headless()
                                            .require_api_version(1, 3, 0)
                                            .build();
}

void Pandora::Cleanup() { garbageCollector.Flush(); }
