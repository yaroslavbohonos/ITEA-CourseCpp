/* Task in Replit(Compiler) - https://replit.com/@Bgns/Overloaded-stack-56#main.cpp

Task: This code implements a simple class that contains elements of any type (you can choose the type, such as integer or anything else).
Stack is a basic data structure with two operations: push, which adds an element to the collection, and pop, which removes the last added 
element. These two methods (push and pop) modify the contents of the stack. In addition to these methods, there is a top method that allows
accessing the top element without modifying the stack. If the stack is empty, an exception is thrown. Your main task is to write the code for
the value retrieval operator without removing it from the stack. Additionally, add your code to handle these specific exceptions. In the main 
code, include some code to take user input for the number of values to be stored and the number of elements to be output from the stack.*/

#include <iostream>
#include <vector>

class Stos {
    std::vector<double> stos;

public:
    Stos() {
        int n = 0;
        std::cout << "Enter the number of elements in the stack: ";
        std::cin >> n;
        std::cout << "Enter the elements:" << std::endl;
        for (int i = 0; i < n; i++) {
            double element;
            std::cin >> element;
            stos.push_back(element);
        }
    }

    void operator+(double element) {
        stos.push_back(element);
    }

    Stos& operator--() {
        if (!stos.empty()) {
            stos.pop_back();
        }
        return *this;
    }

    Stos& operator++() {
        if (!stos.empty()) {
            std::cout << "\nTop element of stack: " << stos.back() << std::endl;
        }
        else {
            std::cout << "\nStack is empty\n";
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Stos& stack) {
        if (!stack.stos.empty()) {
            out << "\nPrinted stack:\n";
            for (int i = stack.stos.size() - 1; i >= 0; i--) {
                out << stack.stos[i] << std::endl;
            }
        }
        return out;
    }
};

int main() {
    std::cout << "The code simulates and creates a new stack data structure.\n";
    Stos A;
    double element1 = 6, element2 = 7;
    std::cout << "\nNumbers 6 and 7 were added to the stack.\n";
    A + 6;
    A + 7;
    std::cout << "\nThe last number was removed from the stack using the pop method.\n";
    --A;
    ++A;
    std::cout << A;

    return 0;
}
