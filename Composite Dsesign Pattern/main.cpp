#include <iostream>
#include <string>
#include <vector>
#include "Directiory.h"
#include "File.h"
#include "FileSystem.h"


int main() { 


  Directory dir("Movie");

  FileSystem* border = new File("Border");

  dir.addFile(border);

  Directory* Comedey  = new Directory("Comedy Movie");

  dir.addFile(Comedey);

  File* Batman = new File("Batman");
  Comedey->addFile(Batman);
  File* Superman = new File("Superman");
  Comedey->addFile(Superman);
  
  
  
  dir.ls();
  

}