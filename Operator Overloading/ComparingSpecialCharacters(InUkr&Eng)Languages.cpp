/* Task in Replit(Compiler) - https://replit.com/@Bgns/Overload-operators-and-with-UkrandEng-letters-55#main.cpp

Task: Create a class for working with special characters. You can name it "SpecialCharacters". 
Here is a list of special characters: { O, A, I, E, H, C, B, K, P, X, T, M }. The special feature 
of these characters is that they are present in both the Ukrainian and English alphabets. 
There is a risk of not noticing the Ukrainian letter in an English word and vice versa. 
Your class should include overloaded operators == and !=. This way, characters that are written 
the same way in different alphabets and can be confused should return true when the == operator 
is applied and false when the != operator is applied. For example, the letter "A" in the
Ukrainian alphabet should be equal to the letter "A" in English.

In the main function, allow the user to compare different characters and display the result of such a comparison. If a character is compared to itself, the result should also be true.*/

#include <bits/stdc++.h>
using namespace std;

class SpecialChar {
  enum SpecialC { O, A, I, E, H, C, B, K, P, X, T, M };
  SpecialC ch1;

public:
  SpecialChar() {
    string character1;
    cout << "Enter character: ";
    cin >> character1;
    ch1 = convert(character1);
  }

  bool operator==(SpecialChar &chSecond) {
    if (get_Char(ch1) == get_Char(chSecond.ch1))
      return true;
    return false;
  }

  bool operator!=(SpecialChar &chSecond) {
    if (get_Char(ch1) == get_Char(chSecond.ch1))
      return false;
    return true;
  }

  int get_Char(SpecialC ch) { return int(SpecialC(ch)); }

  SpecialC convert(const string &str) {
    if (str == "О" || str == "O")
      return O;
    else if (str == "А" || str == "A")
      return A;
    else if (str == "І" || str == "I")
      return I;
    else if (str == "Е" || str == "E")
      return E;
    else if (str == "Н" || str == "H")
      return H;
    else if (str == "С" || str == "C")
      return C;
    else if (str == "В" || str == "B")
      return B;
    else if (str == "К" || str == "K")
      return K;
    else if (str == "Р" || str == "P")
      return P;
    else if (str == "Х" || str == "X")
      return X;
    else if (str == "Т" || str == "T")
      return T;
    else if (str == "М" || str == "M")
      return M;
  }
};

int main() {
  cout << "The programme compares different Ukr. and Eng. characters."
       << "\nЕ.g. if you compared Ukr.\"А\" and Eng.\"A\", it'd return true.\n";
  while (1) {
    SpecialChar A, F;
    if (A == F)
      cout << "First char. equal to second\n";
    if (A != F)
      cout << "First char. isn't equal to second\n";
    cout << "\nPress 0(exit) or 1(continue): ";
    bool choice;
    cin >> choice;
    if (!choice)
      break;
  }
  return 0;
}
