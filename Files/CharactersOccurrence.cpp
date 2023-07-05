/* Task in Replit(Compiler) - https://replit.com/@Bgns/Occurrences-of-characters-47#main.cpp

Task: Read data from a file into memory. Using methods and data structures from the Standard Template Library, calculate the frequency of each individual character in the data.

Create two functions to display the results on the screen:
1) Ordered alphabetically.
2) Ordered by decreasing frequency.

In the main function, create a menu where the user selects the method of displaying the data on the screen. */

#include <bits/stdc++.h>
using namespace std;

void frequence(string s, bool choice) {
  map<char, int> map;
  remove(s.begin(), s.end(), ' ');
  for (char i : s)
    map[i]++;

  if (choice) {
    cout << "\nSorted by numbers:\n";
    multimap<int, char> mMap;
    for (auto& i : map)
      mMap.insert({i.second, i.first});
    for (auto& i : mMap)
      cout << i.second << " - " << i.first << endl;
  } else {
    cout << "\nSorted by symbols:\n";
    set<pair<char, int>> elements(map.begin(), map.end());
    for (auto& i : elements)
      cout << i.first << " - " << i.second << endl;
  }
}

int main() {
  string text;
  bool choice;
  cout << "This is a program to count occurrences of " <<
    "characters from a file.\nThe file data: ";
  ifstream file("text.txt");
  while (getline(file, text))
    cout << text;

  cout << "\n\nThere are 2 options to count and show characters." <<
    "\nEnter 0 (Sort alphabetically) OR 1 (Sort numerically): ";
  cin >> choice;

  frequence(text, choice);
  file.close();
}
