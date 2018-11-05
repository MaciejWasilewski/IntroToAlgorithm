package com.company;


import java.util.ArrayList;

public class Stack {
    private ArrayList<Integer> list;
    private int stackSize;

    public Stack() {
        list = new ArrayList<>(1);
        stackSize = 0;
    }

    public void insert(int elem) {
        if (stackSize == list.size()) {
            list.ensureCapacity(2 * stackSize);
        }
        if (stackSize < list.size()) {
            list.set(stackSize, elem);
        } else if (stackSize == list.size()) {
            list.add(elem);
        } else {
            throw new ArrayIndexOutOfBoundsException("Stack larger than used array!");
        }
        stackSize++;
    }

    public int pop() {
        if (stackSize == 0) {
            throw new ArrayIndexOutOfBoundsException("Stack is empty!");
        }
        stackSize--;
        return list.get(stackSize);

    }

    public void print() {
        System.out.print("[");
        for (int i = 0; i < stackSize; i++) {
            System.out.print(list.get(i) + ", ");
        }
        System.out.print("]\n");
    }
}
