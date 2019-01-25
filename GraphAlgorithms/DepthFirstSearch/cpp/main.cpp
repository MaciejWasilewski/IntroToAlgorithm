#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

enum color {
    white,
    grey,
    black
};

struct extGraphVert {
//    T *val = nullptr;
    char symbol = 0;
    color col = color::white;
    extGraphVert *pred = nullptr;
    int first = INT32_MAX;
    int last = INT32_MAX;
    unsigned int number;

    extGraphVert(char val, unsigned int number) : symbol(val), number(number) {}
};

struct graphComparator {
    bool operator()(const unsigned int &i, const unsigned int &j) {
        return (i) < (j);
    }
};

struct comparatorFinalTimeRev {
    bool operator()(extGraphVert *i, extGraphVert *j) {
        return (i->last) < (j->last);
    }
};

void dfsVisit(const std::map<unsigned int, extGraphVert *> &lookUpNodes,
              std::map<unsigned int, std::vector<unsigned int>> &adjMap,
              extGraphVert *u, int &time, std::vector<unsigned int> &tree);


std::map<unsigned int, std::vector<unsigned int>>
graphTranspose(const std::map<unsigned int, std::vector<unsigned int>> &adjMap);


std::vector<std::vector<unsigned int>> depthFirstSearch(const std::map<unsigned int, extGraphVert *> &lookUpNodes,
                                                        std::map<unsigned int, std::vector<unsigned int>> &adjMap);

std::vector<std::vector<unsigned int>>
stronglyConnectedComponents(const std::map<unsigned int, extGraphVert *> &lookUpNodes,
                            std::map<unsigned int, std::vector<unsigned int>> &adjMap);


int main() {
    std::vector<extGraphVert> nodes;
    nodes.emplace_back('a', 0);
    nodes.emplace_back('b', 1);
    nodes.emplace_back('c', 2);
    nodes.emplace_back('d', 3);
    nodes.emplace_back('e', 4);
    nodes.emplace_back('f', 5);
    nodes.emplace_back('g', 6);
    nodes.emplace_back('h', 7);
    std::map<unsigned int, extGraphVert *> lookUpNodes;
    for (auto &elem:nodes) {
        lookUpNodes.insert(std::pair<unsigned int, extGraphVert *>(elem.number, &elem));
    }
    std::map<unsigned int, std::vector<unsigned int>> adjMap;
    std::vector<unsigned int> oneNode;
    oneNode.push_back(1);
    adjMap[nodes[0].number] = oneNode;

    oneNode.clear();
    oneNode.push_back(2);
    oneNode.push_back(4);
    oneNode.push_back(5);
    adjMap[nodes[1].number] = oneNode;

    oneNode.clear();
    oneNode.push_back(3);
    oneNode.push_back(6);
    adjMap[nodes[2].number] = oneNode;

    oneNode.clear();
    oneNode.push_back(2);
    oneNode.push_back(7);
    adjMap[nodes[3].number] = oneNode;

    oneNode.clear();
    oneNode.push_back(0);
    oneNode.push_back(5);
    adjMap[nodes[4].number] = oneNode;

    oneNode.clear();
    oneNode.push_back(6);
    adjMap[nodes[5].number] = oneNode;

    oneNode.clear();
    oneNode.push_back(5);
    oneNode.push_back(7);
    adjMap[nodes[6].number] = oneNode;

    oneNode.clear();
    oneNode.push_back(7);
    adjMap[nodes[7].number] = oneNode;

    std::vector<std::vector<unsigned int>> allTrees = depthFirstSearch(lookUpNodes, adjMap);
    for (auto &vector: allTrees) {
        std::cout << "New tree\n";
        for (auto &elem: vector) {
            std::cout << lookUpNodes[elem]->symbol << "->";
        }
        std::cout << "\n";
    }
    allTrees= stronglyConnectedComponents(lookUpNodes, adjMap);
    for (auto &vector: allTrees) {
        std::cout << "New component\n";
        for (auto &elem: vector) {
            std::cout << lookUpNodes[elem]->symbol << "->";
        }
        std::cout << "\n";
    }
    return 0;
}

std::map<unsigned int, std::vector<unsigned int>>
graphTranspose(const std::map<unsigned int, std::vector<unsigned int>> &adjMap) {
    std::map<unsigned int, std::vector<unsigned int>> transpose;
    for (const auto &i : adjMap) {
        for (const auto &j: i.second) {
            transpose[j].push_back(i.first);
        }
    }
    return transpose;
}

void dfsVisit(const std::map<unsigned int, extGraphVert *> &lookUpNodes,
              std::map<unsigned int, std::vector<unsigned int>> &adjMap,
              extGraphVert *u, int &time, std::vector<unsigned int> &tree) {

    time++;
//    std::cout<<u->symbol<<"\n";
    u->first = time;
    u->col = color::grey;
    for (auto &v:adjMap[u->number]) {
        extGraphVert &node = *(lookUpNodes.at(v));
        if (node.col == color::white) {
            std::cout << "->" << node.symbol;
            node.pred = u;
            tree.push_back(node.number);
            dfsVisit(lookUpNodes, adjMap, &node, time, tree);

        }
    }
    u->col = color::black;
    time++;
    u->last = time;
}

std::vector<std::vector<unsigned int>>
stronglyConnectedComponents(const std::map<unsigned int, extGraphVert *> &lookUpNodes,
                            std::map<unsigned int, std::vector<unsigned int>> &adjMap) {
    std::vector<std::vector<unsigned int>> allTrees;
    depthFirstSearch(lookUpNodes, adjMap);
    //std::sort (nodes.begin(), nodes.end(), comp);
    std::map<unsigned int, std::vector<unsigned int>> transposed = graphTranspose(adjMap);
    std::priority_queue<extGraphVert *, std::vector<extGraphVert *>, comparatorFinalTimeRev> nodesInOrder;
    for (auto &elem:lookUpNodes) {
        elem.second->col=color::white;
        nodesInOrder.push(elem.second);
    }
//    while(!nodesInOrder.empty())
//    {
//        std::cout<<nodesInOrder.top()->symbol<<"\t"<<nodesInOrder.top()->last<<"\n";
//        nodesInOrder.pop();
//    }
    int time = 0;
    while(!nodesInOrder.empty()) {
        extGraphVert &node = *(nodesInOrder.top());
        nodesInOrder.pop();
        if (node.col == color::white) {
            std::vector<unsigned int> tree;
            tree.push_back(node.number);
            std::cout << node.symbol;
            dfsVisit(lookUpNodes,transposed, &node, time, tree);
            std::cout << "\n";
            allTrees.push_back(tree);
        }

    }

    return allTrees;
}

std::vector<std::vector<unsigned int>> depthFirstSearch(const std::map<unsigned int, extGraphVert *> &lookUpNodes,
                                                        std::map<unsigned int, std::vector<unsigned int>> &adjMap) {
    std::vector<std::vector<unsigned int>> allTrees;
    int time = 0;
    for (auto i = lookUpNodes.begin(); i != lookUpNodes.end(); ++i) {
        extGraphVert &node = *(i->second);
        if (node.col == color::white) {
            std::vector<unsigned int> tree;
            tree.push_back(node.number);
            std::cout << node.symbol;
            dfsVisit(lookUpNodes, adjMap, &node, time, tree);
            std::cout << "\n";
            allTrees.push_back(tree);
        }

    }
    return allTrees;
}