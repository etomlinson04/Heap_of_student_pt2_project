#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "student.h"


void loadStudents(std::vector<Student*>&);
void printStudents(std::vector<Student*>&);
void showStudentNames(std::vector<Student*>&);
void findStudent(std::vector<Student*>&);
void delStudents(std::vector<Student*>&);
std::string menu();

int main() {
  std::vector<Student*> students;
  loadStudents(students);

  std::string choice = menu();
  while (choice != "0") {
    if (choice == "1") {
      showStudentNames(students);
    } else if (choice == "2") {
      printStudents(students);
    } else if (choice == "3") {
      findStudent(students);
    } else {
      std::cout << "Invalid choice." << std::endl;
    }

    choice = menu();
  }


  delStudents(students);
  return 0;
}

void loadStudents(std::vector<Student*>& students) {
  std::ifstream file("students.csv");
  if (!file) {
    std::cerr << "Could not open students.csv" << std::endl;
    return;
  }
  std::string line;
  while (std::getline(file, line)) {
    if (line.empty()) continue;
    Student* s = new Student();
    s->init(line);
    students.push_back(s);
  }
  file.close();
}

void printStudents(std::vector<Student*>& students) {
  for (size_t i = 0; i < students.size(); i++) {
    students[i]->printStudent();
  }
}

void showStudentNames(std::vector<Student*>& students) {
  for (size_t i = 0; i < students.size(); i++) {
    std::cout <<students[i]->getLastFirst() << std::endl;
  }
}

void findStudent(std::vector<Student*>& students) {
  std::string target;
  std::cout << "last name of student: ";
  std::getline(std::cin, target);
  std::cout << "____________________________________" << std::endl;

  bool found = false;
  for (size_t i = 0; i < students.size(); i++) {
    if (students[i]->getLastName().find(target) != std::string::npos) {
      students[i]->printStudent();
      found = true;
    }
  }
  if (!found) std::cout << "No match found." << std::endl;
}

void delStudents(std::vector<Student*>& students) {
  for (size_t i = 0; i < students.size(); i++) {
    delete students[i];
  }
  students.clear();
}

std::string menu() {
  std::string choice;
  std::cout << std::endl;
  std::cout << "0) quit" << std::endl;
  std::cout << "1) print all student names" << std::endl;
  std::cout << "2) print all student data" << std::endl;
  std::cout << "3) find a student" << std::endl;
  std::cout << std::endl << "Please choose 0-3: ";
  std::getline(std::cin, choice);
  return choice;
}


