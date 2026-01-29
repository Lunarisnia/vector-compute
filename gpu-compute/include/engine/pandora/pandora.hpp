#pragma once
#include "engine/garbage_collector/garbage_collector.hpp"
class Pandora {
private:
  GarbageCollector garbageCollector;

private:
  void initDevice();

public:
  void Init();

  void Cleanup();
};
