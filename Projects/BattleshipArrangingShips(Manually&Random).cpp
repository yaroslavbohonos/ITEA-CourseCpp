/* Task in Replit(Compiler) - https://replit.com/@Bgns/Battleship-game-48#main.cpp

Task: Make arranging for the ships in the Battleship Game*/

//#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

const int n = 12;
const int length = 10;
const string mistake = "Invalid coordinates. Enter other ones: ";

bool check(char **desk, int x, int y) {
  if (x > -1 && y > -1 && x < length && y < length) {
    if (desk[x + 1][y + 1] == '*' && desk[x - 1][y - 1] == '*' &&
        desk[x + 1][y - 1] == '*' && desk[x - 1][y + 1] == '*' &&
        desk[x][y - 1] == '*' && desk[x][y + 1] == '*' &&
        desk[x + 1][y] == '*' && desk[x - 1][y] == '*') {
      return false;
    }
  }
  return true;
}

void print(char **desk) {
  cout << endl;
  for (int i = 1; i <= length; i++) {
    for (int j = 1; j <= length; j++) {
      cout << desk[i][j] << " ";
    }
    cout << endl;
  }
}

void save_desk(char **desk) {
  ofstream file("desk.txt");
  for (int i = 1; i <= length; i++) {
    for (int j = 1; j <= length; j++) {
      file << desk[i][j] << " ";
    }
    file << endl;
  }
  file.close();
}

void input(int &x, int &y, int xbottom, int xtop, int ybottom, int ytop) {
  cout << "Enter x and y: ";
  cin >> x >> y;
  while (x < xbottom || x > xtop || y < ybottom || y > ytop) {
    cout << mistake;
    cin >> x >> y;
  }
}

void random_arrange(char **desk) {
  srand(time(NULL));
  int x = 0, y = 0, dir = 0, ship_n = 1;

  for (int ship = 4; ship > 0; ship--) {
    for (int i = 0; i < ship_n; i++) {
    Again:
      dir = rand() % 4 + 1;
      x = rand() % length + 1;
      y = rand() % length + 1;

      switch (dir) {
      case 1: // left
      {
        for (int i = 0; i < ship; i++) {
          if (check(desk, x, y - i)) {
            goto Again;
          }
        }

        for (int i = 0; i < ship; i++) {
          desk[x][y - i] = 'O';
        }
        break;
      }
      case 2: // right
      {
        for (int i = 0; i < ship; i++) {
          if (check(desk, x, y + i)) {
            goto Again;
          }
        }

        for (int i = 0; i < ship; i++) {
          desk[x][y + i] = 'O';
        }
        break;
      }
      case 3: // up
      {
        for (int i = 0; i < ship; i++) {
          if (check(desk,
                    x

                        - i,
                    y)) {
            goto Again;
          }
        }

        for (int i = 0; i < ship; i++) {
          desk[x - i][y] = 'O';
        }
        break;
      }
      case 4: // down
      {
        for (int i = 0; i < ship; i++) {
          if (check(desk, x + i, y)) {
            goto Again;
          }
        }

        for (int i = 0; i < ship; i++) {
          desk[x + i][y] = 'O';
        }
        break;
      }
      }
    }
    ship_n++;
  }
  print(desk);
  save_desk(desk);
}

void manual_arrange(char **desk) {
  int x, y, ship_n = 1;
  for (int ship = 4; ship > 0; ship--) {
    for (int i = 0; i < ship_n; i++) {
    EnterAgain:
      cout << "Enter the direction for a " << ship << "-length ship:\n";
      cout << "l - left\nr - right\nu - up\nd - down\n";
      char direction;
      cin >> direction;

      switch (direction) {
      case 'l': // left
      {
        input(x, y, ship - 1, length, 1, length);

        for (int i = 0; i < ship; i++) {
          if (check(desk, x, y - i)) {
            cout << mistake;
            goto EnterAgain;
          }
        }

        for (int i = 0; i < ship; i++) {
          desk[x][y - i] = 'O';
        }
        break;
      }
      case 'r': // right
      {
        input(x, y, 1, length - ship + 1, 1, length);

        for (int i = 0; i < ship; i++) {
          if (check(desk, x, y + i)) {
            cout << mistake;
            goto EnterAgain;
          }
        }

        for (int i = 0; i < ship; i++) {
          desk[x][y + i] = 'O';
        }
        break;
      }
      case 'u': // up
      {
        input(x, y, 1, length, ship, length);

        for (int i = 0; i < ship; i++) {
          if (check(desk, x - i, y)) {
            cout << mistake;
            goto EnterAgain;
          }
        }

        for (int i = 0; i < ship; i++) {
          desk[x - i][y] = 'O';
        }
        break;
      }
      case 'd': // down
      {
        input(x, y, 1, length, 1, length - ship + 1);

        for (int i = 0; i < ship; i++) {
          if (check(desk, x + i, y)) {
            cout << mistake;
            goto EnterAgain;
          }
        }

        for (int i = 0; i < ship; i++) {
          desk[x +

               i][y] = 'O';
        }
        break;
      }

      default: {
        cout << mistake;
        goto EnterAgain;
        break;
      }
      }
      print(desk);
    }
    ship_n++;
  }
  save_desk(desk);
}

int main() {
  const int n = 12;
  const int length = 10;
  char **desk = new char *[n];

  for (int i = 0; i < n; i++) {
    desk[i] = new char[n];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      desk[i][j] = '*';
    }
  }

  char choice;
  bool check = true;

  while (check) {
    cout << "Would you like to arrange it by methods:\nm - manual\nr - "
            "random\nEnter a letter: ";
    cin >> choice;

    switch (choice) {
    case 'm': {
      manual_arrange(desk);
      check = false;
      break;
    }

    case 'r': {
      random_arrange(desk);
      check = false;
      break;
    }
    default: {
      cout << mistake;
    }
    }
  }

  for (int i = 0; i < n; i++) {
    delete[] desk[i];
  }
  delete[] desk;

  return 0;
}
