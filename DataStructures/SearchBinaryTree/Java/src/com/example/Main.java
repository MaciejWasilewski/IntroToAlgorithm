package com.example;

public class Main {

    public static void main(String[] args) {
        BinarySearchTree<Integer> tree = new BinarySearchTree<>();
        tree.insert(1);
        tree.insert(-1);
        tree.insert(2);
        tree.insert(5);
        tree.insert(0);
        System.out.println(tree);
        System.out.println(tree.maximum());
        System.out.println(tree.minimum());
        System.out.println("Succesor of 1: "+tree.successor(1));
        System.out.println(tree);
        System.out.println(tree.successor(5));

    }
}
