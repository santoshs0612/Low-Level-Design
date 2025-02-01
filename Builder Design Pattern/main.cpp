#include "Student.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
// #include "StudentBuilder.h"
#include "Director.h"
#include "EngineeringStudentBuilder.h"
#include "MBAStudentBuilder.h"

int main() {
  Director director;

  // Create Engineering Student
  EngineeringStudentBuilder engBuilder;
  auto engStudent = director.createStudent(&engBuilder);
  if (engStudent) {
    std::cout << "Engineering Student Details:\n";
    engStudent->display();
  }

  // Create MBA Student
  MBAStudentBuilder mbaBuilder;
  auto mbaStudent = director.createStudent(&mbaBuilder);
  if (mbaStudent) {
    std::cout << "MBA Student Details:\n";
    mbaStudent->display();
  }

  return 0;
}