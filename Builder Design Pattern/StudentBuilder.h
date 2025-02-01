#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Student.h"

// Base Builder class
class StudentBuilder {
protected:
    std::unique_ptr<Student> student;

public:
    StudentBuilder() { student = std::make_unique<Student>(); }
    virtual ~StudentBuilder() = default;

    StudentBuilder &setRollNumber(int rollNumber) {
        student->setRollNumber(rollNumber);
        return *this;
    }

    StudentBuilder &setName(const std::string &name) {
        student->setName(name);
        return *this;
    }

    StudentBuilder &setFatherName(const std::string &fatherName) {
        student->setFatherName(fatherName);
        return *this;
    }

    StudentBuilder &setMotherName(const std::string &motherName) {
        student->setMotherName(motherName);
        return *this;
    }

    virtual StudentBuilder & setSubjects() = 0;

    std::unique_ptr<Student> build() {
        setSubjects();
        return std::move(student);
    }
};