#pragma once
#include "FileSystem.h"
#include <string>
#include <vector>

class File : public FileSystem {
private:
  std::string fileName;

public:
  File(std::string fileName) : fileName(fileName) {}

  void ls() { std::cout << "File Name is - " << fileName << std::endl; }
};