/* Task in Replit(Compiler) - https://replit.com/@Bgns/Calculator-or-65#main.cpp

Task: Write the following program. Create a class that allows the use of a comma to separate 
the integer and fractional parts of floating-point numbers. In other words, such a number 
should be enterable from the keyboard. Implement methods for basic mathematical operations: 
addition, subtraction, multiplication, and division. If the fractional part of both operands 
is zero, also calculate the remainder of the division. Use the following mathematical symbols
to specify the operations: +, -, *, %, or /. The main program performs the selected mathematical 
operation with two numbers entered by the user and then displays the result on the screen. If the 
user enters an invalid symbol, the program should notify about it. Consider the possibility of 
using the keywords const and constexpr in this program. */

#include <iostream>
#include <algorithm>
#include <sstream>

class Calculator {
private:
  bool isValidNumber(const std::string& str) {
    std::istringstream iss(str);
    double value;
    return (iss >> value) && (iss.eof());
  }

protected:
  double num1, num2;

public:
  Calculator() {
    std::string strNum1, strNum2;
    std::cout << "Enter the first operand: ";
    std::cin >> strNum1;

    std::cout << "Enter the second operand: ";
    std::cin >> strNum2;

    std::replace(strNum1.begin(), strNum1.end(), ',', '.');
    std::replace(strNum2.begin(), strNum2.end(), ',', '.');

    if (!isValidNumber(strNum1) || !isValidNumber(strNum2)) {
      std::cout << "Invalid input. Please enter numeric values." << std::endl;
      num1 = 0.0;
      num2 = 0.0;
      return;
    }

    num1 = std::stod(strNum1);
    num2 = std::stod(strNum2);
  }

  double sum() {
    const double sum = num1 + num2;
    std::cout << num1 << " + " << num2 << " = " << sum;
    return sum;
  }

  double multiplication() {
    const double multiply = num1 * num2;
    std::cout << num1 << " * " << num2 << " = " << multiply;
    return multiply;
  }

  double division() {
    if (num2 == 0) {
      std::cout << num1 << " / " << num2 << " = Infinity";
      return 0;
    } else {
      const double divide = num1 / num2;
      std::cout << num1 << " / " << num2 << " = " << divide;
      return divide;
    }
  }

  double modulus() {
    const double modulus = static_cast<int>(num1) % static_cast<int>(num2);
    std::cout << "Attention. The result may be represented in integer type\n";
    std::cout << static_cast<int>(num1) << " % " << num2 << " = " << modulus;
    return modulus;
  }

  double subtraction() {
    const double subtract = num1 - num2;
    std::cout << num1 << " - " << num2 << " = " << subtract;
    return subtract;
  }
};

int main() {
  char ope;
  std::cout << "Enter an operator: +, -, *, /, % or 0 to quit: ";
  std::cin >> ope;

  if (ope == '0')
    return 0;

  Calculator calc;

  switch (ope) {
    case '+':
      calc.sum();
      break;

    case '-':
      calc.subtraction();
      break;

    case '*':
      calc.multiplication();
      break;

    case '/':
      calc.division();
      break;

    case '%':
      calc.modulus();
      break;

    default:
      std::cout << "Error! The operator is not correct";
      break;
  }

  return 0;
}
