#include "engine/garbage_collector/garbage_collector.hpp"
#include <cstdint>
#include <functional>

void GarbageCollector::AddFunction(std::function<void()> deletionFunc) {
  deletionQueue.emplace_back(deletionFunc);
}

void GarbageCollector::Flush() {
  for (uint32_t i = 0; i < deletionQueue.size(); i++) {
    deletionQueue[i]();
  }
  deletionQueue.clear();
}
