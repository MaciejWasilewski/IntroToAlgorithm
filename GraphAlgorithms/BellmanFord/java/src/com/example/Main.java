package com.example;

import java.util.ArrayList;
import java.util.HashMap;

public class Main {

//    class AdjacencyList{
//        private HashMap<Integer,HashMap<Integer, Double>> adjList;
//
//        public AdjacencyList(ArrayList<edge> edgeArrayList) {
//            this.adjList=new HashMap<>();
//            for(edge e: edgeArrayList)
//            {
//                if(!this.adjList.containsKey(e.u))
//                {
//                    this.adjList.put(e.u, new HashMap<>());
//
//                }
//                this.adjList.get(e.u).put(e.v,e.weight);
//            }
//        }
//        public Double returnWeight(int u, int v)
//        {
//            if(this.adjList.containsKey(u) && this.adjList.get(u).containsKey(v))
//            {
//                return this.adjList.get(u).get(v);
//            }
//            else
//            {
//                return Double.POSITIVE_INFINITY;
//            }
//        }
//    }

    public static void main(String[] args) {
        HashMap<Integer, graphNode> graphNodeMap=new HashMap<>();
        graphNodeMap.put(0,new graphNode('s',0));
        graphNodeMap.put(1,new graphNode('t',1));
        graphNodeMap.put(2,new graphNode('x',2));
        graphNodeMap.put(3,new graphNode('y',3));
        graphNodeMap.put(4,new graphNode('z',4));

        HashMap<Integer,HashMap<Integer, Double>> adjWeightList=new HashMap<>();


        adjWeightList.put(0,new HashMap<>());

        adjWeightList.get(0).put(1,(double)3);
        adjWeightList.get(0).put(3,(double)5);


        adjWeightList.put(1,new HashMap<>());

        adjWeightList.get(1).put(3,(double)2);
        adjWeightList.get(1).put(2,(double)6);


        adjWeightList.put(2,new HashMap<>());

        adjWeightList.get(2).put(4,(double)11);


        adjWeightList.put(3,new HashMap<>());

//        adjWeightList.get(3).put(1,(double)1);
//        adjWeightList.get(3).put(2,(double)4);
        adjWeightList.get(3).put(4,(double)6);


        adjWeightList.put(4,new HashMap<>());

//        adjWeightList.get(4).put(0,(double)3);
//        adjWeightList.get(4).put(2,(double)7);

        GraphAlgorithms alg=new GraphAlgorithms(adjWeightList,graphNodeMap);
        alg.bellmanFord(0);
        for(Integer key:graphNodeMap.keySet()) {
            System.out.println(alg.returnRoad(graphNodeMap.get(key)));
        }
        for(Integer g: alg.topologicalSort())
        {
            System.out.println(g);
        }
        alg.DAGShortestPaths(0);
        for(Integer key:graphNodeMap.keySet()) {
            System.out.println(alg.returnRoad(graphNodeMap.get(key)));
        }
    }
}
