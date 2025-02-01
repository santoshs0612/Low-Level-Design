
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>

// Product Class: Student
class Student {
private:
    int rollNumber;
    std::string name;
    std::string fatherName;
    std::string motherName;
    std::vector<std::string> subjects;

public:
    void setRollNumber(int rollNumber) { this->rollNumber = rollNumber; }
    void setName(const std::string &name) { this->name = name; }
    void setFatherName(const std::string &fatherName) { this->fatherName = fatherName; }
    void setMotherName(const std::string &motherName) { this->motherName = motherName; }
    void setSubjects(const std::vector<std::string> &subjects) { this->subjects = subjects; }

    void display() const {
        std::cout << "Student Information:\n";
        std::cout << "Roll Number: " << rollNumber << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Father's Name: " << fatherName << "\n";
        std::cout << "Mother's Name: " << motherName << "\n";
        std::cout << "Subjects: ";
        for (const auto &subject : subjects) {
            std::cout << subject << " ";
        }
        std::cout << "\n\n";
    }
};