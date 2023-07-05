/* Task: Write exceptions for this data structure(stack),
catch and handle them appropriately.
Завдання: напишіть винятки для структури даних стос,
перехопіть і опрацюйте їх належним чином.*/

#include <iostream>
#include <stdexcept>

class Stack {
private:
    int* stackstore;
    long int stacksize;
    int SP;

public:
    Stack(long int size = 1000);
    ~Stack();
    void push(int value);
    int pop();
    long int size();
};

long int Stack::size() {
    return stacksize;
}

Stack::Stack(long int size) {
    if (size <= 0) {
        throw std::length_error("Size must be greater than zero");
    }

    try {
        stackstore = new int[size];
        stacksize = size;
        SP = 0;
    } catch (std::bad_alloc&) {
        std::cout << "Size was specified too large! Creating with pre-defined parameters: size = 1000." << std::endl;
        stacksize = 1000;
        stackstore = new int[stacksize];
        SP = 0;
        throw;
    }
}

Stack::~Stack() {
    delete[] stackstore;
}

void Stack::push(int value) {
    if (SP == stacksize) {
        throw std::logic_error("Stack is full.");
    }
    stackstore[SP++] = value;
}

int Stack::pop() {
    if (SP <= 0) {
        throw std::logic_error("Stack is empty.");
    }
    return stackstore[--SP];
}

int main() {
    try {
        Stack stk(6);
        stk.push(2147483647);
        stk.push(2);
        stk.push(5);
        stk.push(7);
        stk.push(1);
        stk.push(2);
        for (int i = 0; i < stk.size(); i++) {
            std::cout << "Popped: " << stk.pop() << "." << std::endl;
        }
        stk.pop();
    } catch (const std::logic_error& e) {
        std::cout << "Logic error: " << e.what() << std::endl;
    } catch (const std::length_error& e) {
        std::cout << "Memory allocation error: " << e.what() << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cout << "Memory allocation error: " << e.what() << std::endl;
    }

    return 0;
}
