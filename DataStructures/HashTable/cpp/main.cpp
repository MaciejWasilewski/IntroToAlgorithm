#include <iostream>
#include "LinkedList.h"
#include "HashTable.h"

int main() {
//    LinkedList<double> list;
//    list.add(1.0);
//    list.printList();
//    list.add(2.1);
//    list.printList();
//    list.add(3.5);
//    list.printList();
//    list.del(2.0);
//    list.printList();
//    list.del(2.1);
//    list.printList();
    HashTable<double> list(hashFunction);
    list.add(45.0);
    std::cout<<"Added item\n";
    list.search(45.0);
    std::cout<<"dupa"<<std::endl;
    return 0;
}