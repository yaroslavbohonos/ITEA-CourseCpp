/* Task in Replit(Compiler) - https://replit.com/@Bgns/Overloaded-operators-or-Enum-months-of-year-54#main.cpp

Task: Display Month and Season. Write a program that defines an enumeration Season representing the months of the year.
Implement overloaded operators + and - for the Season enum to perform addition and subtraction of months. 
Also, overload the << operator to display the month and corresponding season.*/

#include <iostream>

enum class Season {
  December,
  January,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November
};

Season operator+(Season month, int months) {
  std::cout << "\nMonth after adding " << months << ": ";
  return static_cast<Season>((static_cast<int>(month) + months) % 12);
}

Season operator-(Season month, int months) {
  std::cout << "\nMonth after subtracting " << months << ": ";
  int monthIndex = static_cast<int>(month) - months;
  if (monthIndex < 0)
    monthIndex += 12;
  return static_cast<Season>(monthIndex);
}

std::ostream& operator<<(std::ostream& strm, const Season& month) {
  switch (month) {
    case Season::December:  strm << "month - December. ";    break;
    case Season::January:   strm << "month - January. ";     break;
    case Season::February:  strm << "month - February. ";    break;
    case Season::March:     strm << "month - March. ";       break;
    case Season::April:     strm << "month - April. ";       break;
    case Season::May:       strm << "month - May. ";         break;
    case Season::June:      strm << "month - June. ";        break;
    case Season::July:      strm << "month - July. ";        break;
    case Season::August:    strm << "month - August. ";      break;
    case Season::September: strm << "month - September. ";   break;
    case Season::October:   strm << "month - October. ";     break;
    case Season::November:  strm << "month - November. ";    break;
    default:                strm << "incorrect input. ";
  }

  if (month <= Season::February || month == Season::December)
    strm << "Season - Winter. ";
  else if (month >= Season::March && month <= Season::May)
    strm << "Season - Spring. ";
  else if (month >= Season::June && month <= Season::August)
    strm << "Season - Summer. ";
  else
    strm << "Season - Autumn. ";

  return strm;
}

int main() {
  Season month = Season::October;
  std::cout << "Initial month: " << month;
  month = month + 1;
  std::cout << month;
  month = month - 10;
  std::cout << month << std::endl;
}
