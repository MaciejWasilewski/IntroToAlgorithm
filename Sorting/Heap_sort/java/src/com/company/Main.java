package com.company;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static ArrayList<Double> heap_maxify(ArrayList<Double> array, int parent_index, int heap_size) {
        int left = parent_index * 2 + 1;
        int right = parent_index * 2 + 2;
        int largest = parent_index;
        if (left < heap_size && array.get(left) > array.get(largest)) {
            largest = left;
        }
        if (right < heap_size && array.get(right) > array.get(largest)) {
            largest = right;
        }
        if (largest != parent_index) {
            double temp = array.get(parent_index);
            array.set(parent_index, array.get(largest));
            array.set(largest, temp);
            heap_maxify(array, largest, heap_size);
        }
        return array;
    }

    static ArrayList<Double> build_max_heap(ArrayList<Double> array) {
        for (int i = array.size() / 2 - 1; i > -1; i--) {
            heap_maxify(array, i, array.size());
        }
        return array;
    }

    static ArrayList<Double> heap_sort(ArrayList<Double> array) {
        build_max_heap(array);
        for (int heap_size = array.size() - 1; heap_size > 0; heap_size--) {
            System.out.println(heap_size);
            double temp = array.get(0);
            array.set(0, array.get(heap_size));
            array.set(heap_size, temp);
            heap_maxify(array, 0, heap_size);
        }
        return array;
    }

    public static void main(String[] args) {
        Double a[]=new Double[]{13.0, -3.0, -25.0, 20.0, -3.0, -16.0, -23.0, 18.0, 20.0, -7.0, 12.0, -5.0, -22.0, 15.0, -4.0, 7.0};
        ArrayList<Double> array = new ArrayList(Arrays.asList(a));
        System.out.println(array);
        System.out.println(heap_sort(array));

    }
}
