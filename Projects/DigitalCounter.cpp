/* Task in Replit(Compiler) - https://replit.com/@Bgns/digital-watch-43#main.cpp

Task: A digital counter is a variable with a limited range. Its value resets when the integer value reaches a certain maximum (for example, 59).
The counter serves as a digital clock. Describe a class for such a counter, which would include a constructor. Provide the ability to set the 
maximum and minimum values, create a method to increment the counter by 1, and a method to retrieve the current value. */

#include <iostream>
#include <unistd.h>
using namespace std;

class Watch
{
private:
  int min, max;

public:
  Watch() {
    min = 0; 
    max = 0;
  }
  Watch(int minimum, int maximum):
    min(minimum),max(maximum) {}

  void Input(float min, float max) {
    system("clear");
    if(min/60 >= max) cout << "You've entered a wrong time";
    else{
      cout << "The digital watch is loading (:\n";
      sleep(3);
      int minutes = 0;
      while(min > 59) 
      {
        min-=60;
        minutes++;
      }
      
      for(int seconds = min+1; seconds == 1 || minutes != max; seconds++){
        system("clear");
        cout << "Time: min. - "<< minutes << ": sec. - " << seconds-1 << endl;
        if(seconds > 58) {
          minutes++;
          seconds = 0;
        }
      sleep(1);
      }
    }
  }
};

int main() {
  Watch DigitalWatch;
  int seconds, minutes;
   cout << "Welcome to the digital watch program.\n Enter the starting time in seconds: ";
  cin >> seconds;
  cout << "Enter the ending time in minutes: ";
  cin >> minutes;
  DigitalWatch.Input(seconds, minutes);
}
