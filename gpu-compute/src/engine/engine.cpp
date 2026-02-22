#include "engine/engine.hpp"
#include "engine/pandora/pandora.hpp"

void Engine::Init() { pandora.Init(); }
void Engine::Run() { pandora.Dispatch(1, 1, 1); }

Engine::~Engine() { pandora.Cleanup(); }
