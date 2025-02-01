#pragma once

#include "EngineeringStudentBuilder.h"
#include "MBAStudentBuilder.h"
#include "Student.h"
#include "StudentBuilder.h"

class Director {
public:
  std::unique_ptr<Student> createStudent(StudentBuilder *builder) {
    if (dynamic_cast<EngineeringStudentBuilder *>(builder)) {
      return createEngineeringStudent(builder);
    } else if (dynamic_cast<MBAStudentBuilder *>(builder)) {
      return createMBAStudent(builder);
    }
    std::cerr << "Invalid builder instance!" << std::endl;
    return nullptr;
  }

private:
  std::unique_ptr<Student> createEngineeringStudent(StudentBuilder *builder) {
    return builder->setRollNumber(101)
        .setName("John Doe")
        .setFatherName("Mr. Doe")
        .setMotherName("Mrs. Doe").setSubjects()
        .build();
  }

  std::unique_ptr<Student> createMBAStudent(StudentBuilder *builder) {
    return builder->setRollNumber(202)
        .setName("Jane Doe")
        .setFatherName("Mr. Smith")
        .setMotherName("Mrs. Smith").setSubjects()
        .build();
  }
};