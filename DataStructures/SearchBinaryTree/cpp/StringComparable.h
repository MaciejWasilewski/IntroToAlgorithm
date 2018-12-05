//
// Created by mwasilewski on 30.11.18.
//

#ifndef CPP_STRINGCOMPARABLE_H
#define CPP_STRINGCOMPARABLE_H

#include <string>
#include "Comparable.h"

class StringComparable : public Comparable<std::string> {
private:
    std::string item;


public:

    std::string getitem() override;

    bool compare(Comparable<std::string> *item2) override;


    StringComparable(const std::string &item);
};


#endif //CPP_STRINGCOMPARABLE_H
