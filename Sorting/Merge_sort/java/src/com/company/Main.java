package com.company;

import java.util.ArrayList;

public class Main {
    static void mergeSort(ArrayList<Integer> list, int start, int stop) {
        int length = stop - start;
        System.out.println("Length: "+length);
        if (length == 1) {

        } else {
            int p = length / 2+start;
            System.out.println("p: "+p);
            System.out.println("Sorting sublist: "+list.subList(start,p));
            mergeSort(list, start, p);
            System.out.println("Sorting sublist: "+list.subList(p,stop));
            mergeSort(list, p, stop);
            merge(list,start,p, stop);
        }
        System.out.println("Sorted sublist:\n");
        System.out.println(list.subList(start, stop));

    }

    static void merge(ArrayList<Integer> list, int start, int p, int stop) {
        ArrayList<Integer> a1 = new ArrayList<>(list.subList(start, p));
        ArrayList<Integer> a2 = new ArrayList<>(list.subList(p, stop));
        int i = 0;
        int k = 0;
        while (i < a1.size() || k < a2.size()) {
            if (i == a1.size()) {
                list.set(start + i + k, a2.get(k));
                k++;
                continue;
            }
            if (k == a2.size()) {
                list.set(start + i + k, a1.get(i));
                i++;
                continue;
            }
            if (a1.get(i) < a2.get(k)) {
                list.set(start + i + k, a1.get(i));
                i++;
            } else {
                list.set(start + i + k, a2.get(k));
                k++;
            }
        }
        System.out.println("Merged two sublists:\n");
        System.out.println(list.subList(start, stop));
    }

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(3);
        list.add(2);
        list.add(5);
        list.add(1);
        list.add(6);
        System.out.println(list);
        mergeSort(list, 0, list.size());
        System.out.println(list);
    }
}
