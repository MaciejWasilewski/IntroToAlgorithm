package com.company;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    static ArrayList<Integer> quicksort(ArrayList<Integer> array, int start, int end) {
        if (end - start <= 1)
        {
            return array;
        }
        else
        {
            int pivot=array.get(end-1);
            int pivot_index=start;
            for(int i=start;i<end-1;i++)
            {
                if(array.get(i)<pivot)
                {
                    int temp=array.get(i);
                    array.set(i,array.get(pivot_index));
                    array.set(pivot_index,temp);
                    pivot_index++;

                }
            }
            array.set(end-1,array.get(pivot_index));
            array.set(pivot_index,pivot);
            //System.out.println(array.subList(start,end));
            quicksort(array,start,pivot_index);
            quicksort(array,pivot_index+1,end);
            return array;
        }
    }
    public static void main(String[] args) {
	ArrayList<Integer> array = new ArrayList<>(Arrays.asList(13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7));
        System.out.println(array);
        quicksort(array,0,array.size());
        System.out.println(array);
    }
}
