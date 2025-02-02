#pragma once
#include "FileSystem.h"
#include <string>
#include <vector>
#include "iostream"

class Directory: public FileSystem{

  private:
  std::string directoryName;
  std::vector<FileSystem*> files;
  public:
  Directory(std::string directoryName) : directoryName(directoryName){
    files = std::vector<FileSystem*>();
  }

  void addFile(FileSystem* file){
    files.push_back(file);
  }
  void ls(){
    std::cout << "Directory Name is - " << directoryName << std::endl;
    for(FileSystem* file : files){
      file->ls();
    }
  }
  
};