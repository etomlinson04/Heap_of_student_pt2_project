#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "date.h"

class Student {
private:
  std::string firstName;
  std::string lastName;
  Address address;
  Date birthdate;
  Date gradDate;
  int creditHours;


public:
  Student();
  void init(std::string csvLine);
  void printStudent() const;
  std::string getLastFirst() const;
};


#endif
