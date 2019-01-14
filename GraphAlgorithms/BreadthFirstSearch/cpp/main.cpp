#include <iostream>
#include <vector>
#include <queue>

enum color {
    white,
    grey,
    black
};

//template<class T>
struct extGraphVert {
//    T *val = nullptr;
    char symbol = 0;
    color col = color::white;
    extGraphVert *pred = nullptr;
    int dist = INT32_MAX;
    unsigned int number;

    extGraphVert(char val, unsigned int number) : symbol(val), number(number) {}
};

//template<class T>
class graphForBFS {

private:
    std::vector<std::vector<extGraphVert *>> *extAdjList;
    unsigned int s;
    std::queue<unsigned int> q;
public:
//    adjList[i][0] is the pointer to the ith vertice. adjList[i][j], j>0 is the pointer to the vertices connected to the point i.
    graphForBFS(std::vector<std::vector<extGraphVert *>> *extAdjList, unsigned int s) {
        this->extAdjList = extAdjList;
        this->s = s;
        for (unsigned int i = 0; i < this->extAdjList->size(); i++) {
            if (this->extAdjList->at(i).empty()) {
                throw "Wrong adjacent list - it does not have element at 0.";
            } else {
                extGraphVert *elem = (this->extAdjList->at(i)[0]);
                if (i != s) {
                    elem->col = color::white;
                    elem->dist = INT32_MAX;
                    elem->pred = nullptr;
                }
                elem = (this->extAdjList->at(s)[0]);
                elem->col = color::grey;
                elem->dist = 0;
                elem->pred = nullptr;

            }
        }
        q.push(s);
        std::cout << q.size() << "\n\n";
    }

    void BFS() {
        while (!q.empty()) {
            unsigned int u = q.front();
            q.pop();
            std::cout << q.size() << "\n\n";
            std::cout << "Now considering root vertice: " << this->extAdjList->at(u)[0]->number << ", " <<
                      this->extAdjList->at(u)[0]->symbol << " that has distance: " <<
                      this->extAdjList->at(u)[0]->dist << "\n";
            for (int i = 1; i < this->extAdjList->at(u).size(); i++) {
                extGraphVert *elem = (this->extAdjList->at(u)[i]);
                std::cout << "\tConnected vertice: " << elem->symbol << "\n";
                if (elem->col == color::white) {
                    elem->col = color::grey;
                    elem->dist = this->extAdjList->at(u)[0]->dist + 1;
                    elem->pred = (this->extAdjList->at(u)[0]);
                    std::cout << "\tPushing to queue vertice of number: " << elem->number << "\n";
                    q.push(elem->number);
                }

            }
            this->extAdjList->at(u)[0]->col = color::black;
        }
    }
    void printPath(unsigned int v)
    {
    if(v==this->s)
    {
        std::cout<<this->extAdjList->at(v)[0]->symbol;
    }
    else if(this->extAdjList->at(v)[0]->pred!= nullptr){
        printPath(this->extAdjList->at(v)[0]->pred->number);
        std::cout<<"->"<<this->extAdjList->at(v)[0]->symbol;
    }
    }

};


int main() {
    std::vector<extGraphVert> nodes;
    nodes.emplace_back('r', 0);
    nodes.emplace_back('s', 1);
    nodes.emplace_back('t', 2);
    nodes.emplace_back('u', 3);
    nodes.emplace_back('v', 4);
    nodes.emplace_back('w', 5);
    nodes.emplace_back('x', 6);
    nodes.emplace_back('y', 7);
    std::vector<std::vector<extGraphVert *>> graph;
    std::vector<extGraphVert *> oneNode;
    oneNode.push_back(&(nodes[0]));
    oneNode.push_back(&(nodes[1]));
    oneNode.push_back(&(nodes[4]));
    graph.push_back(oneNode);

    oneNode.clear();
    oneNode.push_back(&(nodes[1]));
    oneNode.push_back(&(nodes[0]));
    oneNode.push_back(&(nodes[5]));
    graph.push_back(oneNode);

    oneNode.clear();
    oneNode.push_back(&(nodes[2]));
    oneNode.push_back(&(nodes[5]));
    oneNode.push_back(&(nodes[6]));
    oneNode.push_back(&(nodes[4]));
    graph.push_back(oneNode);

    oneNode.clear();
    oneNode.push_back(&(nodes[3]));
    oneNode.push_back(&(nodes[2]));
    oneNode.push_back(&(nodes[6]));
    oneNode.push_back(&(nodes[7]));
    graph.push_back(oneNode);

    oneNode.clear();
    oneNode.push_back(&(nodes[4]));
    oneNode.push_back(&(nodes[0]));
    graph.push_back(oneNode);

    oneNode.clear();
    oneNode.push_back(&(nodes[5]));
    oneNode.push_back(&(nodes[1]));
    oneNode.push_back(&(nodes[2]));
    oneNode.push_back(&(nodes[6]));
    graph.push_back(oneNode);

    oneNode.clear();
    oneNode.push_back(&(nodes[6]));
    oneNode.push_back(&(nodes[5]));
    oneNode.push_back(&(nodes[2]));
    oneNode.push_back(&(nodes[3]));
    oneNode.push_back(&(nodes[7]));
    graph.push_back(oneNode);

    oneNode.clear();
    oneNode.push_back(&(nodes[7]));
    oneNode.push_back(&(nodes[6]));
    oneNode.push_back(&(nodes[3]));
    graph.push_back(oneNode);

    graphForBFS g = graphForBFS(&(graph), 1);
    g.BFS();

    for (auto &elem: nodes) {
        std::cout << "Element: " << elem.symbol << ", distance: " << elem.dist << "\n";
    }
    g.printPath(3);
    return 0;
}