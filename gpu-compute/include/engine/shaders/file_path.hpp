#pragma once
#include <string>
class FilePath {
public:
  static std::string Workdir();
  static std::string InWorkdir(const std::string &path);
};
