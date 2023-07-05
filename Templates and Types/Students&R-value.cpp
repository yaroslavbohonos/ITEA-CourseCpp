/* Task in Replit(Compiler) - https://replit.com/@Bgns/Students-stdforward-r-value-or-69#main.cpp

Task: Write a program with a class called "Person" and an inherited class called "Students" that performs the following actions:
1. Outputs the types of objects of different classes using typeid.
2. Uses a variable in the class object that holds the type of the object.
3. Uses decltype to create a variable of the same type as an existing variable.
4. Uses typeid to compare the types of base and derived class objects created using auto and decltype.

The program should be written using functions and classes that allow checking data types and obtaining information about them. 
The user should be able to input values of different types, such as integers (age) and strings (name).*/

#include <iostream>
#include <string>
#include <typeinfo>

class Person
{
protected:
  std::string p_name;
  int p_age;

public:
  Person() {}
  void objType()
  {
    std::cout << "Person's type: " << typeid(*this).name() << std::endl;
  }
};

class Students : public Person
{
public:
  Students(std::string n = "-", int g = 0)
  {
    p_name = n;
    p_age = g;
  }

  template<typename Type>
  void setName1(Type&& name)
  {
    p_name = std::forward<Type>(name);
  }

  void objType()
  {
    std::cout << "Student's type: " << typeid(*this).name() << std::endl;
  }
  
  void Print()
  {
    std::cout << "Name: " << p_name << "\nAge: " << p_age << std::endl;
  }

  void Input()
  {
    std::cout << std::endl;
    char answer;
    while (true)
    {
      std::cout << "\nDo you want to change some information?\nEnter:\n1 - yes\n2 - not\n-> ";
      std::cin >> answer;
      if (answer == '2')
        break;
      else if (answer != '1')
      {
        std::cout << "Invalid input\n";
        break;
      }
      std::cout << "Enter a letter to change:\n1 - name\n2 - age\n-> ";
      std::cin >> answer;

      std::string change;
      int age;
      switch (answer) {
        case '1':
          std::cout << "Name: ";
          std::cin >> change;
          p_name = change;
          break;
        case '2':
          std::cout << "Age: ";
          std::cin >> age;
          p_age = age;
          break;
        default:
          std::cout << "Invalid input\n";
      }
    }
  }
};

int main()
{
  Students student;
  Person person;
  std::cout << "Student's information before actions:\n";
  student.Print();
  std::cout <<"\n\n";
  student.objType();
  person.objType();
  decltype(person) declperson;
  auto autostudent = student;
  std::cout << "The person's class object from decltype: ";
  declperson.objType();

  student.setName1("Den");
  std::cout << "\nStudent's name was set as 'Den'\n\n";

  const std::type_info& ti_person = typeid(person);
  const std::type_info& ti_declperson = typeid(declperson);
  const std::type_info& ti_student = typeid(student);
  const std::type_info& ti_autostudent = typeid(autostudent);

  if (ti_person == ti_student)
    std::cout << "Person and student are equal\n";
  else
    std::cout << "Person and student aren't equal\n";

  if (ti_autostudent == ti_declperson)
    std::cout << "Autostudent and declperson are equal\n";
  else
    std::cout << "Autostudent and declperson aren't equal\n";

  student.Input();
  std::cout << "\nStudent's information after actions:\n";
  student.Print();
}
