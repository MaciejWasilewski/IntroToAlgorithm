package com.company;

public class Main {

    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.insert(1);
        stack.insert(2);
        stack.insert(3);
        stack.print();
        stack.pop();
        stack.print();
        stack.pop();
        stack.print();
        stack.insert(4);
        stack.insert(5);
        stack.insert(6);
        stack.print();
    }
}
