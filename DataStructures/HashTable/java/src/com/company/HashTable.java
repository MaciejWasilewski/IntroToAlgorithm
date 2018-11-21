package com.company;

import java.util.ArrayList;
import java.util.LinkedList;


public class HashTable<Titem> {
    private int hashFunction(Titem item) {
        return item.hashCode() % 41;
    }

    private ArrayList<LinkedList<Titem>> hashTable;

    public HashTable() {
        this.hashTable = new ArrayList<>(41);
    }

    public void add(Titem item) {
        this.hashTable.get(hashFunction(item)).add(item);
    }

    public void remove(Titem item) {
        this.hashTable.get(hashFunction(item)).remove(item);
    }

    @Override
    public String toString() {
        return "HashTable{" +
                "hashTable=" + hashTable +
                '}';
    }

    public Titem search(Titem item)
    {
        int index =hashTable.get(hashFunction(item)).indexOf(item);
        return index!=-1 ? -1: hashTable.get(hashFunction(item)).get(index);
    }
}
