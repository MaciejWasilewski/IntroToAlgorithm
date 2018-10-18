#include <iostream>

using namespace std;
struct indices {
    int start;
    int stop;
};

indices find_max_crossing(int *array, int start, int stop, int mid);

int calculate_subarray(int *array, int start, int stop);

indices maximum_subarray(int *array, int start, int stop) {
    int length = stop - start;
    if (length == 1) {
        indices i{};
        i.start = start;
        i.stop = stop;
        return i;
    } else {
        //mid-point
        int p = length / 2 + start;
        indices i1 = maximum_subarray(array, start, p);

        int s1 = calculate_subarray(array, i1.start, i1.stop);
        indices i2 = maximum_subarray(array, p, stop);

        int s2 = calculate_subarray(array, i2.start, i2.stop);
        indices i3 = find_max_crossing(array, start, stop, p);

        int s3 = calculate_subarray(array, i3.start, i3.stop);
        indices max_i = (s1 > s2) ? i1 : i2;
        int max_s = (s1 > s2) ? s1 : s2;
        max_i = (s3 > max_s) ? i3 : max_i;
        cout << "Considered subarray:\n\t\t[" << array[start];
        for (int i = start + 1; i < stop; i++) {
            cout << ", " << array[i];
        }
        cout << "]\n\t";
        cout << "max left:\t[" << array[i1.start];
        for (int i = i1.start + 1; i < i1.stop; i++) {
            cout << ", " << array[i];
        }
        cout << "]\n\t";
        cout << "sum of subarray is: " << s1 << "\n\t";
        cout << "max right:\t[" << array[i2.start];
        for (int i = i2.start + 1; i < i2.stop; i++) {
            cout << ", " << array[i];
        }
        cout << "]\n\t";
        cout << "sum of subarray is: " << s2 << "\n\t";
        cout << "max mid:\t[" << array[i3.start];
        for (int i = i3.start + 1; i < i3.stop; i++) {
            cout << ", " << array[i];
        }
        cout << "]\n\t";
        cout << "sum of subarray is: " << s3 << "\n\t";
        cout<<"max overall:\t["<<array[max_i.start];
        for (int i = max_i.start + 1; i < max_i.stop; i++) {
            cout << ", " << array[i];
        }
        cout << "].\n*******\n";
        return max_i;

    }
}

indices find_max_crossing(int *array, int start, int stop, int mid) {
    indices out{};
//    cout<<"start "<<start<<" stop "<<stop<<endl;
    //left maximal array
    if (mid - start == 1) {
        out.start = start;
    } else {
        int sum = array[mid - 1];
        int sum_max = sum;
        int start_temp = mid - 1;
        for (int i = mid - 2; i >= start; i--) {
            sum += array[i];
            if (sum > sum_max) {
                sum_max = sum;
                start_temp = i;
            }
        }
        out.start = start_temp;
    }

    //right maximal array
    if (stop - mid == 1) {
        out.stop = stop;
    } else {
        int sum = array[mid];
//        cout<<"\t\t\tsum: "<<sum<<"\n";
        int sum_max = sum;
        int stop_temp = mid+1;
        for (int i = mid + 1; i < stop; i++) {
            sum += array[i];
//            cout<<"\t\t\tsum: "<<sum<<"\n";
            if (sum > sum_max) {
                sum_max = sum;
                stop_temp = i+1;
            }
        }
        out.stop = stop_temp;
    }
    return out;
}

int calculate_subarray(int *array, int start, int stop) {
    int sum = 0;
    for (int i = start; i < stop; i++) {
        sum += array[i];
    }

    return sum;
}
static indices kadane_algorithm(int * array, int length)
{
    indices max_overall={};
    indices max_now={};
    max_now.start=0;
    max_now.stop=1;
    max_overall=max_now;
    int previous=calculate_subarray(array,max_now.start,max_now.stop);
    int max_sum=previous;
    for(int i=1;i<length;i++)
    {
        max_now.stop=i+1;
        if(previous+array[i]<array[i])
        {
            max_now.start=i;
        }
        previous=calculate_subarray(array,max_now.start,max_now.stop);
        if(previous>max_sum)
        {
            max_overall=max_now;
            max_sum=previous;
        }
    }
    return max_overall;
}

int main() {
    int *array = new int[16]{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    indices out = maximum_subarray(array, 0, 16);
    cout << out.start << "\n";
    cout << out.stop << "\n";
//    int sum = 0;
//    for (int i = out.start; i < out.stop; i++) {
//        sum += array[i];
//    }
    cout <<calculate_subarray(array,out.start,out.stop) << endl;
    out=kadane_algorithm(array,16);
    cout << out.start << "\n";
    cout << out.stop << "\n";
//    int sum = 0;
//    for (int i = out.start; i < out.stop; i++) {
//        sum += array[i];
//    }
    cout <<calculate_subarray(array,out.start,out.stop) << endl;
    return 0;
}