/* Task in Replit(Compiler) - https://replit.com/@Bgns/Monsters-auto-decltype-or-67#main.cpp

Task: Declare a class that describes a monster. You can create an enumeration of constants that corresponds to the monster types.
Each monster should have a name (use std::string) and a health count that indicates how much damage it can withstand before dying.
Write a function called printMonster() that will output information about the monster. Declare monsters of various types, initialize
them (including using auto and constructor assignment). When declaring complex data types, use the keyword auto. When creating new 
monsters, use decltype for their declaration. */

#include <iostream>
#include <typeinfo>

enum class TrollsType { Monster1, Monster2, Monster3, Monster4 };

class Trolls
{
private:
    std::string name;
    int hitPoints;
    TrollsType trollsType;

public:
    Trolls(TrollsType trollType, const std::string& n, int hp)
        : trollsType(trollType), name(n), hitPoints(hp)
    {}

    void printMonster()
    {
        std::cout << "Monster's name: " << name << ", hit points: " << hitPoints << std::endl;
    }

    void hitMonster(int kick)
    {
        if (kick >= 0)
        {
            if (hitPoints - kick > 0)
            {
                std::cout << "The monster's " << kick << " hit points are taken away\n";
                hitPoints -= kick;
            }
            else
            {
                std::cout << "The monster's " << kick << " hit points are taken away and it has passed away\n";
                hitPoints = 0;
            }
        }
        else
        {
            std::cout << "Error! Hit value must be greater than or equal to 0\n";
        }
    }
};

int main()
{
    auto name1 = "Jack";
    auto name2 = "Key";
    auto name3 = "Hanny";
    auto name4 = "Bim";
    int hitPoints = 100;

    Trolls orc(TrollsType::Monster1, name1, hitPoints);
    Trolls troll(TrollsType::Monster2, name2, hitPoints);
    Trolls zombie(TrollsType::Monster3, name3, hitPoints);
    Trolls goblin(TrollsType::Monster4, name4, hitPoints);

    orc.printMonster();
    orc.hitMonster(100);
    orc.printMonster();
    std::cout << std::endl;

    troll.printMonster();
    troll.hitMonster(50);
    troll.printMonster();
    std::cout << std::endl;

    zombie.printMonster();
    zombie.hitMonster(75);
    zombie.printMonster();
    std::cout << std::endl;

    goblin.printMonster();
    return 0;
}
