#include "engine/engine.hpp"
#include "engine/pandora/pandora.hpp"

void Engine::Init() { pandora.Init(512); }
void Engine::Run() { pandora.Dispatch(1, 1, 1); }

Engine::~Engine() { pandora.Cleanup(); }
