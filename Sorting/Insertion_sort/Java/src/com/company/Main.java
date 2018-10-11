package com.company;


import java.util.ArrayList;

class Main {
    public static ArrayList<Integer> insertionSort(ArrayList<Integer> list) {
        for (int i = 1; i < list.size(); i++) {
            int j = i - 1;
            int temp = list.get(i);
            while (j > -1 && list.get(j) > temp) {
                list.set(j + 1, list.get(j));
                j--;
            }
            j++;
            list.set(j, temp);
        }
        return list;
    }

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(3);
        list.add(2);
        list.add(5);
        list.add(1);
        System.out.println(list);
        System.out.println(insertionSort(list));
    }
}
