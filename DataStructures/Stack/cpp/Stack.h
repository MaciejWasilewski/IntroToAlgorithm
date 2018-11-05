//
// Created by mwasilewski on 05.11.18.
//
#define DEBUG

#ifndef CPP_STACK_H
#define CPP_STACK_H

#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout <<"\tDebug:"<< str << std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

#include <iostream>

class Stack {
private:
    int *table;
    int stackSize;
    int listSize;
    void resizeTable();
public:
    Stack();
    void insert(int elem);
    int pop();
    void print();

    int getStackSize() const;
};


#endif //CPP_STACK_H
