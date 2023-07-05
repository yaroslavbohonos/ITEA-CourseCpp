#include <iostream>
using namespace std;
 
#include "library.h"
 
Student::Student()
{
  age = 0;
  number = 0;
}

void Student::set(int new_age, int new_number)
{
  age = new_age;
  number = new_number;
}

void Student::Print()
{
  cout << "Student age: " << age << "\nnumber: " << number;
}
 
Student::~Student()
{
age = 0;
number = 0;
}
