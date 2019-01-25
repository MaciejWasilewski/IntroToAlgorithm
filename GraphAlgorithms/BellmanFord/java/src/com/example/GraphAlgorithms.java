package com.example;

import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collector;
import java.util.stream.Collectors;

enum color {
    white,
    gray,
    black
}

class edge {
    graphNode u;
    graphNode v;
    Double weight;

    edge(graphNode u, graphNode v, Double weight) {
        this.u = u;
        this.v = v;
        this.weight = weight;
    }
}

class graphNode {
    graphNode parent = null;
    Double distance = Double.POSITIVE_INFINITY;
    Character symbol;
    Integer index=Integer.MAX_VALUE;
    color col = color.white;
    Integer discoverTime = Integer.MAX_VALUE;
    Integer finishTime = Integer.MAX_VALUE;

    graphNode(Character symbol, Integer i) {
        this.symbol = symbol;
        this.index=i;
    }
}

public class GraphAlgorithms {
    private ArrayList<edge> allEdges;
    private HashMap<Integer, graphNode> graphNodeMap;
    private HashMap<Integer, HashMap<Integer, Double>> adjWeightList;

    public GraphAlgorithms(HashMap<Integer, HashMap<Integer, Double>> adjWeightList, HashMap<Integer, graphNode> graphNodeMap) {
        this.adjWeightList = adjWeightList;
        this.allEdges = new ArrayList<>();
        for (Integer key : adjWeightList.keySet()) {
            for (Integer key2 : adjWeightList.get(key).keySet()) {
                allEdges.add(new edge(graphNodeMap.get(key), graphNodeMap.get(key2), adjWeightList.get(key).get(key2)));
            }
        }

        this.graphNodeMap = graphNodeMap;
    }

    private void DFSVisit(graphNode u, AtomicInteger time, Integer key) {
        time.addAndGet(1);
        u.discoverTime = time.intValue();
        u.col = color.gray;
        for (Integer key2 : adjWeightList.get(key).keySet()) {
            graphNode v = graphNodeMap.get(key2);
            if (v.col == color.white) {
                v.parent = u;
                DFSVisit(v, time, key2);
            }
        }
        u.col = color.black;
        time.addAndGet(1);
        u.finishTime = time.intValue();
    }

    void DFS() {
        for (Integer key : graphNodeMap.keySet()) {
            graphNode temp = graphNodeMap.get(key);
            temp.col = color.white;
            temp.parent = null;
        }
        AtomicInteger time = new AtomicInteger(0);
        for (Integer key : graphNodeMap.keySet()) {
            graphNode temp = graphNodeMap.get(key);
            if (temp.col == color.white) {
                DFSVisit(temp, time, key);

            }

        }
        for (Integer key : graphNodeMap.keySet()) {
            graphNode temp = graphNodeMap.get(key);
            System.out.println(temp.symbol + ": " + temp.discoverTime + "-" + temp.finishTime);

        }
    }
    ArrayList<Integer> topologicalSort()
    {
        DFS();
        ArrayList<graphNode> topSort=new ArrayList<>(graphNodeMap.values());
        topSort.sort(Comparator.comparing(a -> -a.finishTime));
        return topSort.stream().map(a -> a.index).collect(Collectors.toCollection(ArrayList::new));
    }
    public void DAGShortestPaths(Integer s)
    {

        ArrayList<Integer> topSorted= topologicalSort();
        initializeSingleSource(s);
        for(Integer u: topSorted)
        {
            for(Integer v: adjWeightList.get(u).keySet())
            {
                relax(u, v, adjWeightList.get(u).get(v));
            }
        }
    }
    private void initializeSingleSource(int s) throws IllegalArgumentException {
        graphNode temp;
        for (Integer key : this.graphNodeMap.keySet()) {
            temp = this.graphNodeMap.get(key);
            temp.distance = Double.POSITIVE_INFINITY;
            temp.parent = null;
        }
        if (!this.graphNodeMap.containsKey(s)) {
            throw new IllegalArgumentException("Source s has index that does not belong to the defined nodes!");
        }
        temp = this.graphNodeMap.get(s);
        temp.distance = (double) 0;
    }

    private void relax(Integer i, Integer j, Double w) {
        graphNode u = graphNodeMap.get(i);
        graphNode v = graphNodeMap.get(j);
        if (v.distance > u.distance + w) {
            v.distance = u.distance + w;
            v.parent = u;
        }
    }

    boolean bellmanFord(int s) {
        initializeSingleSource(s);
        for (int i = 0; i < graphNodeMap.size() - 1; i++) {
            for (edge e : allEdges) {
                relax(e.u.index, e.v.index,e.weight);
            }
        }
        for (edge e : allEdges) {
            graphNode u = e.u;
            graphNode v = e.v;
            Double w = e.weight;
            if (v.distance > u.distance + w) {
                return false;
            }

        }
        return true;
    }

    String returnRoad(graphNode v) {

        String x = "";
        if (v.parent != null) {
            x = returnRoad(v.parent) + "->";
        }
        return x + v.symbol;

    }
}
