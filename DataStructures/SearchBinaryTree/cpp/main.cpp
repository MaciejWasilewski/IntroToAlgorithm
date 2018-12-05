#include <iostream>

#include "StringComparable.h"
#include <string>
#include "BinarySearchTree.h"

int main() {
    /*std::cout << "Hello, World!" << std::endl;
    StringComparable a=StringComparable("Hello");
    std::cout<<a.getitem()<<std::endl;
    std::string b="dupa";
    std::cout<<"Is "<<a.getitem()<<" smaller than "<<b<<"?\n";
    Comparable<std::string> * b2= new StringComparable(b);
    std::cout<<a.compare(b2);*/
    BinarySearchTree<int> tree=BinarySearchTree<int>();
    //BinarySearchTree<int>::node x;
    tree.insert(1);
    tree.insert(2);
    tree.insert(-1);
    tree.inorder_tree_walk();
    std::cout<<std::endl;
    tree.delete_node(1);
    tree.inorder_tree_walk();
    std::cout<<std::endl;
    tree.delete_node(3);
    tree.inorder_tree_walk();
    std::cout<<std::endl;
    tree.delete_node(-1);
    tree.inorder_tree_walk();
    std::cout<<std::endl;
    tree.insert(-1);
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    tree.inorder_tree_walk();
    std::cout<<std::endl;
    std::cout<<tree.min()->item<<std::endl<<tree.max()->item<<std::endl;
    return 0;
}