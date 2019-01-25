package com.example;

import java.lang.reflect.Array;
import java.util.*;

enum color {
    white,
    grey,
    black
}

public class Main {
    static class GraphNode {
        int number = -1;
        GraphNode parent = null;
        char symbol = 0;
        color col = color.white;
        int distance = Integer.MAX_VALUE;

        public GraphNode(int number, char symbol) {
            this.number = number;
            this.symbol = symbol;
        }
    }

    public static void BFS(ArrayList<GraphNode> nodes, ArrayList<ArrayList<Integer>> adjList, int root) throws Exception {
        for (GraphNode node : nodes) {
            node.col = color.white;
        }
        nodes.get(root).col = color.grey;
        nodes.get(root).distance = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int uIndex = q.remove();
            GraphNode u = nodes.get(uIndex);
            if (uIndex != u.number) {
                throw new IllegalArgumentException("Index " + uIndex + " of graph node does not match its intrinsic number: " + u.number);
            }
            for (int nIndex : adjList.get(uIndex)) {

                GraphNode node = nodes.get(nIndex);
                if (node.col == color.white) {
                    node.col = color.grey;
                    node.distance = u.distance + 1;
                    node.parent = u;
                    q.add(nIndex);
                }
            }
            u.col = color.black;

        }

    }

    public static void main(String[] args) {
        char[] charArray = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y'};
        ArrayList<Character> charList = new ArrayList<>(8);
        ArrayList<GraphNode> nodes = new ArrayList<>(8);
        int i = 0;
        for (char c : charArray) {
            nodes.add(new GraphNode(i, c));
            i++;
        }
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>(8);
        adjList.add(new ArrayList<>(Arrays.asList(1, 4)));
        adjList.add(new ArrayList<>(Arrays.asList(0, 5)));
        adjList.add(new ArrayList<>(Arrays.asList(5, 6, 4)));
        adjList.add(new ArrayList<>(Arrays.asList(2, 6, 7)));
        adjList.add(new ArrayList<>(Arrays.asList(0)));
        adjList.add(new ArrayList<>(Arrays.asList(1, 2, 6)));
        adjList.add(new ArrayList<>(Arrays.asList(5, 2, 3, 7)));
        adjList.add(new ArrayList<>(Arrays.asList(6, 3)));
        try {
            BFS(nodes, adjList,1);

        } catch (Exception e) {
            e.printStackTrace();
        }
        for(GraphNode node: nodes) {
            System.out.println(node.symbol + " " + node.distance);
        }

    }
}
