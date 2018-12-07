#include <iostream>

#include "RedBlackTree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    RedBlackTree<int> tree = RedBlackTree<int>();
    for (int i = 0; i < 32; i++) {
        tree.insert(i);
    }

    std::cout << tree.toString() << std::endl;
    std::cout << tree.toString2() << std::endl;
    return 0;
}