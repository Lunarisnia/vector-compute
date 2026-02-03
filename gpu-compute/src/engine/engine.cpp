#include "engine/engine.hpp"
#include "engine/pandora/pandora.hpp"

void Engine::Init() { pandora.Init(); }
void Engine::Run() {}

Engine::~Engine() { pandora.Cleanup(); }
