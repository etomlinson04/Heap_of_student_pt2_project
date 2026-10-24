#include <iostream>
#include <sstream>
#include <vector>
#include "student.h"


Student::Student() {
  firstName = "";
  lastName = "";
  address = new Address();
  birthdate = new Date();
  gradDate = new Date();
  creditHours = 0;
}

Student::~Student() {
  delete address;
  delete birthdate;
  delete gradDate;
}

void Student::init(std::string csvLine) {
  std::vector<std::string> f;
  std::stringstream ss(csvLine);
  std::string field;
  while (std::getline(ss, field, ',')) {
    f.push_back(field);
  }
  firstName = f[0];
  lastName = f[1];
  address->init(f[2], f[3], f[4], f[5]);
  birthdate->init(f[6]);
  gradDate->init(f[7]);
  std::stringstream converter(f[8]);
  converter >> creditHours;
}

void Student::printStudent() const {
  std::cout << firstName << " " << lastName << std::endl;
  address->printAddress();
  std::cout << "DOB: ";
  birthdate->printDate();
  std::cout << "Grad: ";
  gradDate->printDate();
  std::cout << "Credits: " << creditHours << std::endl;
  std::cout << "____________________________________" << std::endl;
}

std::string Student::getLastFirst() const {
  return lastName + ", " + firstName;
}

std::string Student::getLastName() const {
  return lastName;
}


