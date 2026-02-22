#include "engine/shaders/file_path.hpp"
#include <filesystem>
#include <string>

std::string InWorkdir(const std::string &path) {
  return FilePath::Workdir() + "/" + path;
}

std::string Workdir() { return std::filesystem::current_path(); }
