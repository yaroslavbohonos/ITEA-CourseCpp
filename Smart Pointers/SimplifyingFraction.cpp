/* Task in Replit(Compiler) - https://replit.com/@Bgns/Unique-ptr-reduction-of-rational-fractions-stdGCPor73#main.cpp

Task: Implement a Fraction class that represents fractions and includes functionality to simplify the fractions. 
Test the class by creating a fraction object with the numerator 49 and denominator 11711, and then print the fraction along with its simplified form.*/

#include <iostream>
#include <memory>
#include <algorithm>

class Fraction {
private:
    int m_numerator = 0;
    int m_denominator = 1;

    friend int GCD(const Fraction& f1) {
        return std::__gcd(f1.m_numerator, f1.m_denominator);
    }

public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator == 0 ? 1 : denominator) {}

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
        out << f1.m_numerator << "/" << f1.m_denominator;
        std::cout << "\n(Additional scoring) Simplified fraction: " << f1.m_numerator / GCD(f1) << "/" << f1.m_denominator / GCD(f1);
        return out;
    }
};

void printFraction(const Fraction& fraction) {
    std::cout << fraction;
}

int main() {
    std::unique_ptr<Fraction> fractionPtr = std::make_unique<Fraction>(49, 11711);
    printFraction(*fractionPtr);
    return 0;
}
