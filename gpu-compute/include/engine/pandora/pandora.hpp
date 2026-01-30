#pragma once
#include "VkBootstrap.h"
#include "engine/garbage_collector/garbage_collector.hpp"
class Pandora {
private:
  GarbageCollector garbageCollector;
  vkb::Instance instance;

private:
  void initDevice();

public:
  void Init();

  void Cleanup();
};
