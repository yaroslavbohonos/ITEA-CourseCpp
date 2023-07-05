/* Task: Write a program that calculates the area of a triangle. This program should use custom exceptions.
Add a specific attribute to the exception to pass a message to the user.

Завдання: Напишіть програму, яка обчислює площу трикутника. Ця програма має використовувати ваші власні 
винятки для спілкування з кодом вищого рівня. Додайте певний атрибут за винятком, щоб передати повідомлення користувачеві.*/

#include <iostream>
#include <cmath>

class InvalidSideException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Error: All sides of the triangle must be greater than 0.";
    }
};

class InvalidTriangleException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Error: The triangle with given sides does not exist.";
    }
};

class Triangle
{
public:
    Triangle() {}
    ~Triangle() {}

    void validateSides(double side1, double side2, double side3)
    {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0)
        {
            throw InvalidSideException();
        }
    }

    void validateTriangle(double side1, double side2, double side3)
    {
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
        {
            throw InvalidTriangleException();
        }
    }

    double calculateArea()
    {
        double side1, side2, side3;
        std::cout << "Enter the sides of the triangle:\n";
        std::cout << "Side 1: ";
        std::cin >> side1;
        std::cout << "Side 2: ";
        std::cin >> side2;
        std::cout << "Side 3: ";
        std::cin >> side3;

        try
        {
            validateSides(side1, side2, side3);
            validateTriangle(side1, side2, side3);

            double semiperimeter = (side1 + side2 + side3) / 2;
            double area = sqrt(semiperimeter * (semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3));
            std::cout << "Area of the triangle: " << area << std::endl;
            return area;
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
            return 0.0;
        }
    }
};

int main()
{
    Triangle triangle;
    triangle.calculateArea();
    return 0;
}
