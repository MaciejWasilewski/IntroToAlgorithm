package com.company;



import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    static int quicksort_search(ArrayList<Integer> array, int start, int stop, int item) {
        if (item >= stop || item < start) {
            throw new IllegalArgumentException();
        }
        if (stop - start <= 1) {
            return array.get(item);
        }
        int pivot = array.get(stop - 1);
        int pivot_index = start;
        for (int i = start; i < stop - 1; i++) {
            if (array.get(i) < pivot) {
                int temp = array.get(i);
                array.set(i, array.get(pivot_index));
                array.set(pivot_index, temp);
                pivot_index++;
            }
        }
        if (item == pivot_index) {
            return pivot;

        }
        array.set(stop - 1, array.get(pivot_index));
        array.set(pivot_index, pivot);
        if (item < pivot_index) {
            return quicksort_search(array, start, pivot_index, item);
        }
        return quicksort_search(array, pivot_index + 1, stop, item);
    }

    public static void main(String[] args) {
        Integer array[] = new Integer[]{6, 2, 8, 3, 6, 8, 3, 1, 3, 65, 8, 9};
        ArrayList<Integer> array2 = new ArrayList<Integer>(Arrays.asList(array));
        for (int i = 0; i < array2.size(); i++) {
            System.out.println(quicksort_search(array2, 0, array2.size(), i) + "\n");
        }


    }
}
