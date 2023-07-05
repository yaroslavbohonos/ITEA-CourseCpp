/* Task in Replit(Compiler) - https://replit.com/@Bgns/Forbidden-symbols-or-class-Vector-58#main.cpp

Task: Create a class that can only contain the following characters: '₴1234567890-=!"No;%:?()_+/*,.
If an attempt is made to enter any other symbol into the array, handle it by displaying an appropriate message on the screen.
Try to construct an expression from the allowed elements of the array and output it to the screen. */


#include <iostream>
#include <vector>
using namespace std;

template <typename T> class Vector
{
protected:
  vector <T> myvector;
  vector <T> Forbidden {
  "`", "₴", "1", "2", "3",
  "4", "5", "6", "7", "8",
  "9", "0", "-", "=", "!",
  "\"", "№", "#", ";", "%",
  ":", "?", "(", ")", "_",
  "+", "/", "*", "\\", ",", "."
  };

public:
  bool isForbiddenSymbols(T symbol)
  {
    for(int i = 0; i < Forbidden.size(); i++)
      if(Forbidden.at(i) == symbol)
        return true;
    return false;
  }

  void push(T symbol)
  {
    if(isForbiddenSymbols(symbol))
      myvector.push_back(symbol);
    else cout << "The symbol: " << symbol << " is forbidden\n";
  }

  friend ostream& operator<< (ostream &out, Vector<string> &vect)
  {
    if(!vect.myvector.empty()) 
    {
      for(int i = 0; i < vect.myvector.size(); i++)
        cout << vect.myvector.at(i) << " ";
      return out;
    }
    return out;
  }
};

int main()
{
  Vector<string> A;  
  A.push("3");
  A.push("/");
  A.push("10");
  A.push("^");
  A.push("-1");
  A.push("3");
  A.push("=");
  A.push("1");
  cout << A;
}
