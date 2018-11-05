

#include <iostream>
#include "Stack.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Stack stack=Stack();
    stack.insert(1);
    stack.print();
    stack.insert(2);
    stack.print();
    std::cout<<stack.pop()<<std::endl;
    stack.print();
    return 0;
}