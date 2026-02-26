#include "engine/engine.hpp"
#include "engine/pandora/pandora.hpp"
#include "fmt/base.h"

void Engine::Init() { pandora.Init(512 * sizeof(float)); }
void Engine::Run() {
  pandora.Upload(69);
  pandora.Dispatch(1, 1, 1);
  auto result = pandora.Download();
  for (const auto &res : result) {
    fmt::println("Result: {}", res);
  }
}

Engine::~Engine() { pandora.Cleanup(); }
