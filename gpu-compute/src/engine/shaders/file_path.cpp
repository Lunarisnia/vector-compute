#include "engine/shaders/file_path.hpp"
#include <filesystem>
#include <string>

std::string FilePath::Workdir() { return std::filesystem::current_path(); }

std::string FilePath::InWorkdir(const std::string &path) {
  return Workdir() + "/" + path;
}
