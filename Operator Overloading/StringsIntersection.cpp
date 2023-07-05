/* Task in Replit(Compiler) - https://replit.com/@Bgns/Concatination-duplicates-in-two-strings-53#main.cpp

Task: Create a function that generates a string containing the intersection of two strings, i.e., the common characters between both strings. 
For example, the intersection of "sdqcg" and "rgfas34" would be "sg". Overload the * (multiplication) operator to implement the function. */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class String
{
protected:
  string word1;
public:
  String(string s) { word1 = s; }
  String() 
  { 
    cout << "Enter a word: ";
    cin >> word1;
  }
  string get_value() { return word1; }
  
  String operator*(String& W)
  {
    string word2 = W.get_value();
    string temp;
    
    for (int i = 0; i < word1.size(); i++)
    {
      if (word2.find(word1[i]) != string::npos && temp.find(word1[i]) == string::npos)
        temp += word1[i];
    }
    
    String result(temp);
    return result;
  }

  void Show() {
    cout << "\nString after crossing: " << word1;
  }
};

int main() {
  cout << "The program overloads operator \"*\"";
  cout << "\nIt crosses through elements and finds duplicates.\n";
  
  String A, B;
  String C("");
  C = A * B;
  C.Show();

  return 0;
}
