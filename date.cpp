#include <iostream>
#include <sstream>
#include "date.h"


Date::Date() {
  month = 1;
  day = 1;
  year = 1970;
}

Date::Date(int m, int d, int y) {
  init(m, d, y);
}

void Date::init(int m, int d, int y) {
  month = m;
  day = d;
  year = y;
}

void Date::init(std::string dateString) {
  // dateString is mm/dd/yyyy
  std::stringstream converter;
  std::string sMonth;
  std::string sDay;
  std::string sYear;

  //seperating to temp strings
  converter.str(dateString);
  std::getline(converter, sMonth, '/');
  std::getline(converter, sDay, '/');
  std::getline(converter, sYear);

  //converting to ints
  converter.clear();
  converter.str("");
  converter << sMonth << " " << sDay << " " << sYear;
  converter >> month >> day >> year;
}


std::string Date::getMonthName() const {
  std::string names[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  if (month < 1 || month > 12) return "Unknown";
  return names[month - 1];
}

void Date::printDate() const {
  std::cout << getMonthName() << " " << day << ", " << year << std::endl;
}


