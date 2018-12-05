//
// Created by mwasilewski on 30.11.18.
//

#include "StringComparable.h"


StringComparable::StringComparable(const std::string &item) : item(item) {}

std::string StringComparable::getitem() {
    return this->item;
}

bool StringComparable::compare(Comparable<std::string> *item2) {
    int l1 = this->getitem().length();
    int l2 = item2->getitem().length();
    char *temp2 = new char[item2->getitem().length() + 1];
    int minimum = std::min(l1, l2);
    char *temp1 = new char[this->getitem().length() + 1];
    std::strcpy(temp2, item2->getitem().c_str());
    std::strcpy(temp1, this->getitem().c_str());
    for(int i=0;i<l1;i++)
    {
        temp1[i]=tolower(temp1[i]);
    }
    for(int i=0;i<l2;i++)
    {
        temp2[i]=tolower(temp2[i]);
    }
    for (int i = 0; i < minimum; i++) {
        if (temp1[i] > temp2[i]) {
            delete temp1, temp2;
            return false;
        } else if (temp1[i] < temp2[i]) {
//            std::cout<<temp1[i]<<temp2[i]<<"\n";
            delete temp1, temp2;
            return true;
        }
    }
    if (l1 < l2) {
        delete temp1, temp2;
        return true;
    }
    delete temp1, temp2;
    return false;
}
