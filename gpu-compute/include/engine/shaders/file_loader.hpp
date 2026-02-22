#pragma once
#include <string>
#include <vector>
class FileLoader {
public:
  static std::vector<char> LoadBinaryFile(const std::string &path);
};
