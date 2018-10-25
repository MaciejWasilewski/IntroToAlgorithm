#include <iostream>

using namespace std;

void max_heapify(double *array, int i, int heap_size) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    cout << "parent:\t" << array[i] << "\n";
    cout << "left:\t" << ((l < heap_size) ? (to_string(array[l])) : "no left leaf") << "\t";
    cout << "right:\t" << ((r < heap_size) ? (to_string(array[r])) : "no right leaf)") << "\n\n";
    if (l < heap_size && array[l] > array[largest]) {
        largest = l;
    }
    if (r < heap_size && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != i) {
        cout << "change of parent and one of leafs!\n";
        double temp = array[largest];
        array[largest] = array[i];
        array[i] = temp;
        cout << "[";
        for (int i = 0; i < 16; i++) {
            cout << array[i] << ", ";
        }
        cout << "]\n\n\n";
        max_heapify(array, largest, heap_size);

    }

}

void build_max_heap(double *array, int size) {
    int heap_size = size;
    for (int i = heap_size / 2 - 1; i > -1; i--) {
        max_heapify(array, i, heap_size);
    }
    cout << "[";
    for (int i = 0; i < 16; i++) {
        cout << array[i] << ", ";
    }
    cout << "]\n";
}

void heap_sort(double *array, int size) {
    build_max_heap(array, size);
    int heap_size = size;
    for (int i = size - 1; i > 0; i--) {
        double temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        //cout<<temp<<endl;
        heap_size--;
        max_heapify(array, 0, heap_size);
    }
}

int main() {
    double *array = new double[16]{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    cout << "[";
    for (int i = 0; i < 16; i++) {
        cout << array[i] << ", ";
    }
    cout << "]\n";
    heap_sort(array, 16);
    cout << "[";
    for (int i = 0; i < 16; i++) {
        cout << array[i] << ", ";
    }
    cout << "]\n";
    delete[] array;
    return 0;
}