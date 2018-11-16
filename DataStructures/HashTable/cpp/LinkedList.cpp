//
// Created by mwasilewski on 16.11.18.
//

#include "LinkedList.h"


//template<typename T>
//LinkedList<T>::LinkedList(T *values, int *nexts, int *prevs) {
//    this->values = new T[10];
//    this->nexts = new int[10];
//    this->prevs = new int[10];
//    this->lastEl = 0;
//    this->size = 10;
//}
//
//template<typename T>
//LinkedList<T>::~LinkedList() {
//    delete[] this->nexts;
//    delete[] this->prevs;
//    delete[] this->values;
//}
//
//template<typename T>
//void LinkedList<T>::increaseList() {
//    T *new_values = new T[2 * this->size];
//    for (int i = 0; i < (this->lastEl); i++) {
//        new_values[i] = this->values[i];
//    }
//    delete[] this->values;
//    this->values = new_values;
//
//    int *new_nexts = new int[2 * this->size];
//    for (int i = 0; i < (this->lastEl); i++) {
//        new_nexts[i] = this->nexts[i];
//    }
//    delete[] this->nexts;
//    this->nexts = new_nexts;
//
//    int *new_prevs = new int[2 * this->size];
//    for (int i = 0; i < (this->lastEl); i++) {
//        new_prevs[i] = this->prevs[i];
//    }
//    delete[] this->prevs;
//    this->prevs = new_prevs;
//    this->size = 2 * this->size;
//}
//
