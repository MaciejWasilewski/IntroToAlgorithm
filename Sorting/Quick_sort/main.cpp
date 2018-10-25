#include <iostream>

void print_array(double *array, int start, int end);

void quick_sort(double *array, int start, int end) {
    print_array(array, start, end);
    if (end - start > 1) {
        std::cout << start << " " << end << "\n";
        double p = array[end - 1];
        std::cout << p << std::endl;
        int index = start;
        for (int i = start; i < end - 1; i++) {
            if (array[i] < p) {
                index++;
                if (index != i + 1) {
                std::cout << "Switching " << array[i] << " and " << array[index - 1] << "\n";
                std::cout << "Switching " << i << " and " << index - 1 << "\n";

                double temp = array[i];
                std::cout << temp << "\t" << array[index - 1] << "\n";
                array[i] = array[index - 1];
                std::cout << array[i] << "\t" << array[index - 1] << "\n";
                array[index - 1] = temp;
                std::cout << array[i] << "\t" << array[index - 1] << "\n";
            }
            print_array(array, start, end);
        }


    }
    array[end - 1] = array[index];
    array[index] = p;
    std::cout << "After sorting:\n";
    print_array(array, start, end);
    quick_sort(array, start, index);
    quick_sort(array, index + 1, end);
}

print_array(array, start, end
);
}

void print_array(double *array, int start, int end) {
    std::cout << "[" << array[start];
    for (int i = start + 1; i < end; i++) {
        std::cout << ", " << array[i];
    }
    std::cout << "]\n";
}

int main() {
    double *array = new double[13]{-2, 3, 10, 6, 2, 7, 5, 8, -1, 67, -3, -4, 4};
    print_array(array, 0, 13);
    quick_sort(array, 0, 13);
    print_array(array, 0, 13);

    delete[] array;
    return 0;
}