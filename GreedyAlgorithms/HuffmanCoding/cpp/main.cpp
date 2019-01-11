#include <iostream>
#include <set>
#include <vector>
#include <map>

class node {
private:


public:
    double freq = 0;
    char c = 0;
    node *left = nullptr;
    node *right = nullptr;

    node() { std::cout << "New node\n"; }

    explicit node(std::pair<char, double> p) {
        this->c = p.first;
        this->freq = p.second;
    }

//    explicit node(node *x) {
//        std::cout << "New node from pointer\n";
//        this->left = x->left;
//        this->right = x->right;
//        this->freq = x->freq;
//        this->c = x->c;
//        this->code = x->code;
//    }

    ~node() {
        delete this->left;
        delete this->right;

        std::cout << "Deleting node " << this->freq << "\n";
    }

    void special_delete() {
        if (this->right != nullptr) {
            this->right->special_delete();
            this->right = nullptr;
        }
        if (this->left != nullptr) {
            this->left->special_delete();
            this->left = nullptr;
        }
        this->~node();
    }


    bool operator()(node *x, node *y) const { return x->freq < y->freq; }
};

node* huffman(std::multiset<node *, node> *mset) {
    size_t n = mset->size();
    node *x;
    std::multiset<node *, node>::iterator it;
    for (int i = 0; i < n - 1; i++) {
        it = mset->begin();
        node *z = new node();
        z->left = *it;
        std::cout << "erasing address to node with frequency: " << (*it)->freq << "\n";
        mset->erase(it);
        it = mset->begin();
        z->right = *it;
        z->freq = z->right->freq + z->left->freq;
        std::cout << "erasing address to node with frequency: " << (*it)->freq << "\n";
        mset->erase(it);
        mset->insert(z);
    }
    it = mset->begin();
    x=*it;
    return x;

}

void retrieveHuffmanCodes(std::string s, node *root, std::map<char, std::string> *codeMap) {
    if (root->left == nullptr || root->right == nullptr) {
        if (!(root->left == nullptr && root->right == nullptr)) {
            throw "The tree should be full and apparently it is not!";
        }
        std::cout << root->c << ": " << s << "\n";
        codeMap->insert(std::pair<char, std::string>(root->c, s));
    } else {

        retrieveHuffmanCodes(s + "0", root->left, codeMap);
        retrieveHuffmanCodes(s + "1", root->right, codeMap);
    }
}

int main() {
    std::multiset<node *, node> mset;
    //std::priority_queue<node, std::vector<node>, node> mset;
//std::cout<<(a->operator()(b,a));
    std::vector<std::pair<char, double>> elems = {std::pair<char, double>('a', 45), std::pair<char, double>('b', 13),
                                                  std::pair<char, double>('c', 12), std::pair<char, double>('d', 16),
                                                  std::pair<char, double>('e', 9), std::pair<char, double>('f', 5)};
    for (auto &elem : elems) {
        mset.insert(new node(elem));
    }
    node *x = huffman(&mset);

    std::map<char, std::string> cmap;
    retrieveHuffmanCodes("", x, &cmap);
    std::cout << cmap['b'] << "\n";
    delete x;
    return 0;
}