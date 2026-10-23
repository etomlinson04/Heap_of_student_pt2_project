#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
  int month;
  int day;
  int year;


public:
  Date();
  Date(int m, int d, int y);
  void init(std::string mmddyyyy);
  void init(int m, int d, int y);
  std::string getMonthName() const;
  void printDate() const;
};

#endif


