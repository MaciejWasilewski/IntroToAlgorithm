package com.company;

import java.util.ArrayList;

public class Main {
    static ArrayList<Integer> selectionSort(ArrayList<Integer>list)
    {
        int l=list.size();
        for(int i=0;i<l-1;i++)
        {
            int min=i;
            for(int j=i+1;j<l;j++)
            {
                if(list.get(min)>list.get(j))
                {
                    min=j;
                }
            }
            int temp=list.get(i);
            list.set(i,list.get(min));
            list.set(min,temp);
        }
        return list;
    }
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(3);
        list.add(2);
        list.add(5);
        list.add(4);
        System.out.println(list);
        System.out.println(selectionSort(list));
    }
}
