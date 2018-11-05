//
// Created by mwasilewski on 05.11.18.
//

#include "Stack.h"

Stack::Stack() {
    this->table = new int[1];
    this->stackSize = 0;
    this->listSize = 1;
}

void Stack::resizeTable() {
    DEBUG_MSG("Resizing table!");
    int *newTable = new int[2 * listSize];
    for (int i = 0; i < listSize; i++) {
        newTable[i] = this->table[i];

    }
    delete[] this->table;
    this->table = newTable;
    this->listSize *= 2;
}

void Stack::insert(int elem) {
    if (this->stackSize == this->listSize) {
        this->resizeTable();
    }
    this->table[stackSize] = elem;
    stackSize++;
}

int Stack::pop() {
    if (stackSize == 0) {
        throw "There is no elements in the stack!";
    }
    stackSize--;
    return table[stackSize];
}

void Stack::print() {
    std::cout << "[";
    for (int i = 0; i < this->getStackSize(); i++) {
        std::cout << this->table[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int Stack::getStackSize() const {
    return stackSize;
}
