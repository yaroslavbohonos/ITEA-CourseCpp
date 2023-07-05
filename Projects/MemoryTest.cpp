/* Task in Replit(Compiler) - https://replit.com/@Bgns/Memory-game-46#main.cpp

Task: Create a class that contains a vector (or array). Implement the following:
0) Constructor that creates an object with an empty vector.
1) Constructor that fills the vector with random integers from 10 to 99, a total of 12 numbers.
2) Method to display the twelve elements of the vector in a 4x3 table format for 20 seconds.
3) Create a method to allow the user to input 12 elements for the vector from the keyboard.
4) Function or method to compare two objects that contain vectors, which returns the number of matching elements.

In the main program, inform the user that they need to remember as many numbers as possible and display the vector 
with random numbers on the screen. You can provide the user with hints about how much time they have to memorize the 
numbers. After the numbers disappear, ask the user to recall and enter them from the keyboard. Compare the results 
with the previous vector and display the number of correctly remembered numbers on the screen.*/

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Game
{
  vector<int> numbers, numbers2;

public:
  Game()
  {
    vector<int> numbers;
  }

  Game(vector<int> n)
  {
    for (int i = 0; i < 12; ++i)
    {
      n[i] = rand() % 89 + 10;
    }
    numbers = n;
  }

  void Print()
  {
    cout << "\nThe numbers will disappear in 20 seconds\n";
    for (int i = 0; i < numbers.size(); i++)
    {
      if (i == 4 || i == 8)
        cout << endl;
      cout << numbers[i] << " ";
    }
    cout << endl;
    sleep(18);
    system("clear");
  }

  void Input()
  {
    cout << "Enter the remembered numbers in sequence:" <<
            "\n\t#1 - 0 #2  - 0 #3  - 0  #4  - 0\n"<<
            "\t#5 - 0 #6  - 0 #7  - 0  #8  - 0\n"<<
            "\t#9 - 0 #10 - 0 #11 - 0  #12 - 0\n";
    int number, counter = 0;
    cout << "Enter the elements by numbers:\n";
    for (int i = 0; i < 12; i++)
    {
      cout << "#" << i + 1 << ": ";
      cin >> number;
      if (CheckNumber(number))
      {
        counter++;
        numbers2.push_back(number);
      }
    }
    cout << "Correct answers: " << counter << "\nRight answers: ";
    for (int i : numbers2)
      cout << i << " ";

    cout << "\nThe 4x3 matrix:\n";
    for (int i = 0; i < numbers.size(); i++)
    {
      if (i == 4 || i == 8)
        cout << endl;
      cout << numbers[i] << " ";
    }
    cout << "\nThe game has ended";
  }

  bool CheckNumber(int number)
  {
    for (int i = 0; i < 12; i++)
    {
      if (number == numbers[i])
      {
        numbers[i] = -1;
        return true;
      }
    }
    return false;
  }
};

int main()
{
  srand(time(NULL));
  vector<int> numbers(12, 0);
  Game MemoryGame(numbers);
  cout << "Welcome to 'Memory Tester', a game where you test your memory skills." <<
          "\nYou will be shown 12 numbers arranged in a 4x3 matrix.\n" <<
          "They will disappear in 20 seconds, so be careful." <<
          "\nYou need to enter them in the sequence or in any order:";
  cout << "\n\t#1 - 0 #2  - 0 #3  - 0  #4  - 0\n"<<
            "\t#5 - 0 #6  - 0 #7  - 0  #8  - 0\n"<<
            "\t#9 - 0 #10 - 0 #11 - 0  #12 - 0\n";
  string desire;
  cout << "\nAre you ready to start? Enter 'yes-1' or 'no-0':";
  cin >> desire;
  if (desire == "yes" || desire == "1")
  {
    MemoryGame.Print();
    MemoryGame.Input();
  }
  else
    cout << "The game has ended";
}
