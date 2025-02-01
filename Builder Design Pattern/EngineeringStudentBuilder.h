#pragma once
#include "StudentBuilder.h"
#include <string>
#include <vector>

// Specialized Builder for Engineering Students
// Specialized Builder for MBA Students
// class EngineeringStudentBuilder : public StudentBuilder {
// public:
//   void setSubjects() override {
//     student->setSubjects({"DBMS", "Algo", "Data Structures",
//                           "Operating Systems", "Computer Networks",
//                           "Computer Architecture", "Computer Organization"});
//   }
// };
class EngineeringStudentBuilder : public StudentBuilder {

public:
  StudentBuilder &setSubjects() override {

    // hard coding the subject
    student->setSubjects(
        {"Math", "Physics", "Computer Science", "Electronics"});
    return *this;
  }
};