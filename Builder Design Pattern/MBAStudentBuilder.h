#pragma once 
#include "StudentBuilder.h"
#include <string>
#include <vector>


// Specialized Builder for MBA Students
// class MBAStudentBuilder : public StudentBuilder {
// public:
//     void setSubjects() override {
//         student->setSubjects({"Marketing", "Finance", "Operations Management", "Strategy"});
//     }
// };

class MBAStudentBuilder : public StudentBuilder {
public:
    StudentBuilder &setSubjects() override {
        student->setSubjects({"Marketing", "Finance", "Operations Management", "Strategy"});
        return *this;
    }
};