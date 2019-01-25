package com.example;

import java.util.*;

import static java.lang.Integer.MAX_VALUE;

class graphEdge implements Comparable<graphEdge>
{
    public double weight=0;
    public graphNode startNode;
    public graphNode endNode;

    @Override
    public String toString() {
        return "Edge: " +
                "weight=" + weight +
                ", " + startNode +
                "-" + endNode;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        graphEdge edge = (graphEdge) o;
        return Double.compare(edge.weight, weight) == 0 &&
                startNode.equals(edge.startNode) &&
                endNode.equals(edge.endNode);
    }

    @Override
    public int hashCode() {
        return Objects.hash(weight, startNode, endNode);
    }

    public graphEdge(double weight, graphNode startNode, graphNode endNode) {
        this.weight = weight;
        if(startNode.compareTo(endNode)<0)
        {this.startNode = startNode;
        this.endNode = endNode;}
        else
        {
            this.startNode = endNode;
            this.endNode = startNode;
        }

    }

    @Override
    public int compareTo(graphEdge o) {
        return (int)(this.weight-o.weight);
    }
}
class graphNode implements Comparable<graphNode>
{
    public graphNode(char symbol, int index) {
        this.symbol = symbol;
        this.index = index;
    }

    @Override
    public String toString() {
        return (Character.toString(symbol));
    }

    public char symbol='0';
    public int index= MAX_VALUE;
    public int finalTime=MAX_VALUE;
    public int startTime=MAX_VALUE;
    public graphTree tree=null;

    public void setTree(graphTree tree) {
        this.tree = tree;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        graphNode graphNode = (graphNode) o;
        return index == graphNode.index;
    }

    @Override
    public int hashCode() {
        return Objects.hash(index);
    }
    public graphTree findSet(){
        return tree;
}
    @Override
    public int compareTo(graphNode o) {
        return this.index - o.index;
    }

}
class graphTree implements Comparable<graphTree>
{
    @Override
    public String toString() {
        return "graphTree{" +
                "tree=" + tree +
                '}';
    }

    //private ArrayList<graphNode> tree;
    public TreeSet<graphNode> tree;
    @Override
    public int compareTo(graphTree o) throws IllegalStateException {
        if(this.tree.isEmpty() || o.tree.isEmpty()) {
            throw new IllegalStateException("Trees cannot be empty");
        }
        return this.tree.first().compareTo(o.tree.first());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        graphTree graphTree = (graphTree) o;
        return tree.equals(graphTree.tree);
    }

    @Override
    public int hashCode() {
        return Objects.hash(tree);
    }

    public void union(graphTree o)
    {
        tree.addAll(o.tree);
        for (graphNode node: tree
             ) {
            node.tree=this;
        }
        System.out.println(tree);
    }

    public graphTree(graphNode node) {
        this.tree = new TreeSet<>();
        this.tree.add(node);
        node.tree=this;
    }
}


public class Main {

    public static PriorityQueue<graphEdge> mstKruskal(PriorityQueue<graphEdge> allEdges, HashMap<Integer, graphNode> allNodes)
    {
        PriorityQueue<graphEdge> mst=new PriorityQueue<>();
        ArrayList<graphTree> forest=new ArrayList<>(allNodes.size());
        for (Map.Entry<Integer, graphNode> entry : allNodes.entrySet()) {
            graphNode node = entry.getValue();
            forest.add(new graphTree(node));
            //System.out.println("New forest  of size: "+forest.get(forest.size()-1).tree.size());
        }
        for(graphEdge edge: allEdges)
        {
            if(!edge.startNode.tree.equals(edge.endNode.tree))
            {
                mst.add(edge);
                edge.startNode.tree.union(edge.endNode.tree);
            }
        }

        return mst;
    }
    public static void main(String[] args) {
        HashMap<Integer, graphNode> allNodes=new HashMap<>();
        allNodes.put(0, new graphNode('a',0));
        allNodes.put(1, new graphNode('b',1));
        allNodes.put(2, new graphNode('c',2));
        allNodes.put(3, new graphNode('d',3));
        allNodes.put(4, new graphNode('e',4));
        allNodes.put(5, new graphNode('f',5));
        allNodes.put(6, new graphNode('g',6));
        allNodes.put(7, new graphNode('h',7));
        allNodes.put(8, new graphNode('i',8));


        PriorityQueue<graphEdge> allEdges=new PriorityQueue<>();
        allEdges.add(new graphEdge(4,allNodes.get(0),allNodes.get(1)));
        allEdges.add(new graphEdge(8,allNodes.get(1),allNodes.get(2)));
        allEdges.add(new graphEdge(7,allNodes.get(2),allNodes.get(3)));
        allEdges.add(new graphEdge(9,allNodes.get(3),allNodes.get(4)));
        allEdges.add(new graphEdge(10,allNodes.get(5),allNodes.get(4)));
        allEdges.add(new graphEdge(14,allNodes.get(5),allNodes.get(3)));
        allEdges.add(new graphEdge(4,allNodes.get(5),allNodes.get(2)));
        allEdges.add(new graphEdge(2,allNodes.get(6),allNodes.get(5)));
        allEdges.add(new graphEdge(1,allNodes.get(7),allNodes.get(6)));
        allEdges.add(new graphEdge(11,allNodes.get(7),allNodes.get(1)));
        allEdges.add(new graphEdge(8,allNodes.get(7),allNodes.get(0)));


        allEdges.add(new graphEdge(2,allNodes.get(8),allNodes.get(2)));
        allEdges.add(new graphEdge(6,allNodes.get(8),allNodes.get(6)));
        allEdges.add(new graphEdge(7,allNodes.get(8),allNodes.get(7)));
        //System.out.println(allEdges);
        PriorityQueue<graphEdge> mst=mstKruskal(allEdges,allNodes);
        for(graphEdge edge:mst)
        {
            System.out.println(edge.startNode.symbol+"-"+edge.endNode.symbol+": "+edge.weight);
        }

    }
}
