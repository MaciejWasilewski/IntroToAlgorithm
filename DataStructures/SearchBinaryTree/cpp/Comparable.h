//
// Created by mwasilewski on 30.11.18.
//

#ifndef CPP_COMPARABLE_H
#define CPP_COMPARABLE_H

#include <cstring>
#include <cmath>
#include <iostream>

template<class T>
class Comparable {
public:
    virtual bool compare (Comparable<T>* item2)=0;
    virtual T getitem() = 0;
};


#endif //CPP_COMPARABLE_H
