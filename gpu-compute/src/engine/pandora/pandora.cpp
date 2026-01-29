#include "engine/pandora/pandora.hpp"

void Pandora::Init() {}

void Pandora::Cleanup() { garbageCollector.Flush(); }
