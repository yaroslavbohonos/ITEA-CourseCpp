/* Task in Replit(Compiler) - https://replit.com/@Bgns/Forbidden-symbols-or-class-Vector-58#main.cpp

Task: Create a class that can only contain the following characters: '₴1234567890-=!"No;%:?()_+/*,.
If an attempt is made to enter any other symbol into the array, handle it by displaying an appropriate message on the screen.
Try to construct an expression from the allowed elements of the array and output it to the screen. */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Vector {
protected:
  std::vector<std::string> myvector;
  std::vector<std::string> forbiddenSymbols{
      "`", "₴", "1", "2", "3",  "4", "5",  "6", "7", "8", "9",
      "0", "-", "=", "!", "\"", "№", "#",  ";", "%", ":", "?",
      "(", ")", "_", "+", "/",  "*", "\\", ",", "."};

public:
  bool isForbiddenSymbol(const std::string &symbol) {
    return std::find(forbiddenSymbols.begin(), forbiddenSymbols.end(),
                     symbol) != forbiddenSymbols.end();
  }

  void push(const std::string &symbol) {
    if (isForbiddenSymbol(symbol)) {
      myvector.push_back(symbol);
    } else {
      std::cout << "The symbol: " << symbol << " is forbidden\n";
    }
  }

  friend std::ostream &operator<<(std::ostream &out, const Vector &vect) {
    if (!vect.myvector.empty()) {
      for (const auto &symbol : vect.myvector) {
        out << symbol << " ";
      }
    }
    return out;
  }
};

int main() {
  Vector A;
  A.push("3");
  A.push("/");
  A.push("10");
  A.push("^");
  A.push("-1");
  A.push("3");
  A.push("=");
  A.push("1");
  std::cout << A << std::endl;

  return 0;
}
