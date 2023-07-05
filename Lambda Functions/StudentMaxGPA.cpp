/* Task in Replit(Compiler) - https://replit.com/@Bgns/lambda-function-with-a-class-Studentor-70#main.cpp

Task: Create a class called "Students" that will store the student's name, surname, and average grade.
Create an array (vector) of students and a function to find the student with the highest grade.
In the main function, print the name of the found student on the screen.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Person {
protected:
  std::string p_name;
  std::string p_surname;
  double p_GPA;  // Grade Point Average

public:
  Person() {}
};

class Student : public Person {
public:
  Student(std::string n = "-", std::string s = "-", double g = 0)
  {
    p_name = n;
    p_surname = s;
    p_GPA = g;
  }

  void Print() {
    std::cout << "Name: " << p_name << "\nSurname: " << p_surname;
    std::cout << "\nGPA (Grade Point Average): " << p_GPA << "\n\n";
  }

  double get_GPA() const { return p_GPA; }
  std::string get_fullname() { return p_name + " " + p_surname; }
};

int main() {
  Student student1("Jake", "Back", 10);
  Student student2("Laura", "Sankis", 11.5);
  Student student3("Nany", "Hesh", 9.5);
  Student student4("Jackob", "Holey", 11);
  Student student5("Gregor", "Day", 10);

  std::vector<Student*> students = {&student1, &student2, &student3, &student4, &student5};

  for (const auto& student : students) {
    student->Print();
  }

  auto maxGPA = std::max_element(students.begin(), students.end(),
    [](Student* a, Student* b) {
      return a->get_GPA() < b->get_GPA();
    }
  );

  std::cout << "The student " << (*maxGPA)->get_fullname() << " has the maximum GPA = " << (*maxGPA)->get_GPA();

  return 0;
}
