/* Goal: Try to make your own library */

#include <iostream>
using namespace std;

#include "library.h"

int main() {
  int age, number;
  cout << "Enter student age and number:";
  cin>>age;
  cin>>number;
  Student student1;
  student1.set(age, number);
  student1.Print();
}
