#include <iostream>

int quick_select(int *array, int start, int end, int item) {
    if (item < start || item >= end) {
        throw "Searched item beyond scope of the array";
    }
    if (end - start <= 1) {
        return array[start];
    }
    int pivot = array[end - 1];
    int pivot_index = start;
    for (int i = start; i < end; i++) {
        if (array[i] < pivot) {
            int temp = array[i];
            array[i] = array[pivot_index];
            array[pivot_index] = temp;
            pivot_index++;
        }
    }
    if (pivot_index == item) {
        return pivot;
    }
    array[end - 1] = array[pivot_index];
    array[pivot_index] = pivot;
    if (item < pivot_index) {
        return quick_select(array, start, pivot_index, item);
    } else {
        return quick_select(array, pivot_index + 1, end, item);
    }
}

int main() {
    int * array=new int[10]{0,5,2,73,6,6,43,7,4,4};
    std::cout<<quick_select(array,0,10,10);
    return 0;
}