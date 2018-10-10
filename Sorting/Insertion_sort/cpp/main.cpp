#include <iostream>

using namespace std;

double *sort(double *array, int size, bool reverse) {
    int no_op = 0;
    for (int i = 1; i < size; i++) {
        no_op++;
        double temp = array[i];
        no_op++;
        int j = i - 1;
        no_op++;
        while (j >=0 && ((!reverse)?(array[j]>temp):(array[j]<temp))){
            no_op++;
            //cout<<"\t"<<j<<"\t"<<(j>=0)<<"\t"<<(j >=0 && (!reverse)?(array[j]>temp):(array[j]<temp))<<endl;
            array[j + 1] = array[j];
            no_op++;
            j--;
            no_op++;
        }

        array[j+1] = temp;
        no_op++;

    }
    cout << "Number of operations: " << no_op << endl;
    return array;
}

int main() {
    auto *array = new double[10];
    for (int i = 0; i < 10; i++) {
        array[i] = abs(5-i);
    }
    for (int i = 0; i < 10; i++) {
        cout << "\t" << array[i];
    }
    cout<<endl;
    array = sort(array, 10, true);
    for (int i = 0; i < 10; i++) {
        cout << "\t" << array[i];
    }
    cout<<endl;
    array= sort(array, 10, false);
    for (int i = 0; i < 10; i++) {
        cout << "\t" << array[i];
    }
    cout<<endl;
    return 0;
}