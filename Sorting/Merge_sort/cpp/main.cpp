#include <iostream>

int *merge(int *list, int start, int p, int stop);
int *mergeSort(int *list, int start, int stop) {
    int size = stop - start;
    if (size == 1) {
        return list;
    } else {
        int p = size / 2 + start;
        mergeSort(list, start, p);
        mergeSort(list, p, stop);
        merge(list, start, p, stop);
    }
}

int *merge(int *list, int start, int p, int stop) {
    int i=0;
    int k=0;
    while(i<)
    return list;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}