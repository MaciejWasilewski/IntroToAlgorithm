//
// Created by mwasilewski on 16.11.18.
//

#ifndef CPP_HASHTABLE_H
#define CPP_HASHTABLE_H

#include "LinkedList.h"

template<class T>
int hashFunction(T key) {
    return (int) key % 41;
}

template<class T>
class HashTable {
private :
    LinkedList<T> *hashTable;
    int (*hashfun)(T);

public:
    HashTable(int (*fun)(T)) {
        hashfun=fun;
        hashTable = new LinkedList<T>[41];
    }

    virtual ~HashTable() {
        delete[] hashTable;
    }

    void add(T item)
    {
        std::cout<<this->hashfun(item)<<std::endl;
        hashTable[this->hashfun(item)].add(item);
    }
    void remove(T item)
    {
//        std::cout<<"Removing item from list nr "<<this->hashfun(item)<<"\n";
        hashTable[this->hashfun(item)].del(item);
    }
    void search(T item)
    {
        linkedListElem<T> * temp=this->hashTable[this->hashfun(item)].search(item);
        if (temp==NULL)
        {
            std::cout<<"Nothing found."<<"\n";
        }
        else
        {
            std::cout<<"Found item!\n";
        }
    }
    void print()
    {
        for(int i=0;i<41;i++)
        {
            std::cout<<"Hash value: "<<i<<"\n\t";
            this->hashTable[i].printList();
            std::cout<<"\n";
        }
    }

};


#endif //CPP_HASHTABLE_H
