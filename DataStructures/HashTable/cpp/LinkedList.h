//
// Created by mwasilewski on 16.11.18.
//

#ifndef CPP_LINKEDLIST_H
#define CPP_LINKEDLIST_H

#include <iostream>

template<class T>
struct linkedListElem {
    T value;
    linkedListElem<T> *next;
    linkedListElem<T> *previous;
};

template<class T>
class LinkedList {
private:
    linkedListElem<T> *head;
public:
    LinkedList();

    void add(T item);

    linkedListElem<T> *search(T item);

    void del(T item);

    void printList();

    virtual ~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList() {
    this->head = NULL;
}

template<class T>
void LinkedList<T>::add(T item) {
    if (this->head == NULL) {
        linkedListElem<T> *temp = new linkedListElem<T>;
        temp->value = item;
        temp->previous = NULL;
        temp->next = NULL;
        this->head = temp;
    } else {
        linkedListElem<T> *temp = new linkedListElem<T>;
        temp->value = item;
        temp->previous = NULL;
        temp->next = this->head;
        temp->next->previous = temp;
        this->head = temp;
    }
}

template<class T>
linkedListElem<T> *LinkedList<T>::search(T item) {
    //std::cout << "Searching for item " << item << "\n";
    linkedListElem<T> *temp = this->head;
    if (head != NULL) {
        linkedListElem<T> *temp = this->head;
        if (temp->value == item) {
            //std::cout << "Found item 1: " << temp->value << "\n";
            return temp;
        }
        while (temp->next != NULL) {
            if (temp->next->value == item) {
                //std::cout << "Found item 2: " << temp->next->value << "\n";
                //std::cout << "a" << temp->next;
                //std::cout << std::endl;
                return temp->next;
            } else {
                temp = temp->next;
            }
        }

    }
    return NULL;
}

template<class T>
void LinkedList<T>::del(T item) {
    linkedListElem<T> *temp = this->search(item);
//    std::cout << temp << std::endl;
    if (temp != NULL) {
//        std::cout << "not null" << std::endl;
        if (this->head == temp) {
//            std::cout << "This is head of a list\n";
            if (temp->next != NULL) {
//                std::cout << temp->next;
                this->head = temp->next;
                temp->next->previous = NULL;
            } else {
                this->head = NULL;
            }
        } else {
//            std::cout << "not head" << std::endl;
            if (temp->next != NULL) {
                //std::cout<<"has next"<<std::endl;
                temp->next->previous = temp->previous;
                //std::cout<<"updated previous<=next"<<std::endl;
            }
            //std::cout<<"previous: "<<temp->previous<<std::endl;
            temp->previous->next = temp->next;
            //std::cout<<"updated previous=>next"<<std::endl;
        }
        //std::cout << "Deleting item: " << temp->value << "\n";
        delete temp;
        this->printList();
    }
}

template<class T>
void LinkedList<T>::printList() {
    if (head != NULL) {
        linkedListElem<T> *temp = this->head;
        std::cout << "[" << temp->value;
        while (temp->next != NULL) {
            std::cout << ",\t" << temp->next->value;
            temp = temp->next;
        }
        std::cout << "]\n";

    } else {
        std::cout << "The list is empty!";
    }
}

template<class T>
void delete_all_next(linkedListElem<T> *item) {
    if (item->next != NULL) {
        delete_all_next(item->next);
        std::cout << "Deleting " << item->value << "\n";
        delete item;
    } else {
        std::cout << "Deleting " << item->value << "\n";
        delete item;
    }
}

template<class T>
LinkedList<T>::~LinkedList() {
    if (this->head != NULL) {
        delete_all_next(this->head);
    }
}

#endif //CPP_LINKEDLIST_H
