//
// Created by mwasilewski on 07.12.18.
//

#ifndef CPP_REDBLACKTREE_H
#define CPP_REDBLACKTREE_H

#include <cstdlib>
#include <string>
#include <iostream>

//T has to have comparison operators overloaded!!!
template<class T>
class RedBlackTree {
private:
    struct node {
        node *left = nullptr;
        bool isRed = false;
        node *right = nullptr;
        node *parent = nullptr;
        T item = 0;
    };
    node *root;

    void rotateLeft(node *subRoot) {
        if (subRoot->right == nullptr) {
            throw "Cannot rotate to left, because the node does not have a right child";
        }
        node *y = subRoot->right;
        if (subRoot->parent != nullptr) {
            (subRoot->parent->left == subRoot) ? subRoot->parent->left = y : subRoot->parent->right = y;
            y->parent = subRoot->parent;
        } else {
            this->root = y;
            y->parent = nullptr;
        }
        subRoot->right = y->left;
        y->left = subRoot;
        if (subRoot->right != nullptr) {
            subRoot->right->parent = subRoot;
        }
    }

    void rotateRight(node *subRoot) {
        if (subRoot->left == nullptr) {
            throw "Cannot rotate to right, because the node does not have a left child";
        }
        node *y = subRoot->left;
        if (subRoot->parent != nullptr) {
            (subRoot->parent->left == subRoot) ? subRoot->parent->left = y : subRoot->parent->right = y;
            y->parent = subRoot->parent;
        } else {
            this->root = y;
            y->parent = nullptr;
        }
        subRoot->left = y->right;
        y->right = subRoot;
        if (subRoot->left != nullptr) {
            subRoot->left->parent = subRoot;
        }

    }


    void rebalanceTree(node *newNode) {
        node *z = newNode;
        while (z != nullptr && z->parent != nullptr && z->parent->isRed) {
            //z, z->parent exist and, what is important, z->parent for sure is not the root (otherwise it would be black)
            //z->parent is red => red black tree property is violated! (red parent has red children (z))
            if (z->parent == z->parent->parent->left) {
                //z->parent is a left child of grandparent.
                node *y = (z->parent->parent != nullptr) ? z->parent->parent->right : nullptr;
                if (y != nullptr && y->isRed) {
                    //uncle y exists and is red
                    z->parent->isRed = false;
                    y->isRed = false;
                    if (z->parent->parent != nullptr) {
                        //I think this condition is always true, since z->parent is red
                        // (so it is not the root)
                        z->parent->parent->isRed = true;
                    }
                    //violation in subtree fixed up -> the original z is red, its parent is black, the uncle is black and the
                    // grandfather is red ->subtree with grandfather as a root is ok.
                    //the global violation can still exist - if the grandparent was the root and if the grandgrandparent was red
                    z = z->parent->parent;

                } else {
                    //uncle y does not exist or is black
                    if (z == z->parent->right) {
                        //z is the right children, z->parent is red
                        z = z->parent;
                        this->rotateLeft(z);
                        //violation is not fixed up - original z is still red and its former parent (now left child) is also red
                        //this is where the root could remain red (because we exit the while loop)
                    } else {
                        //z is the left children, is red. z->parent is also red
                        z->parent->isRed = false;
                        z->parent->parent->isRed = true;
                        this->rotateRight(z->parent->parent);
                        //violation of two red nodes is fixed up. z->parent is now black. grandparent is now right child of parent and is red.
                        //it has to be red because the uncle is black and the other child of parent is black or does not exist
                        //the root of the subtree, the former parent is black - if its the root of the whole tree, then there is no other violations
                    }
                }

            } else {
                //z->parent is a right child of grandparent.
                node *y = (z->parent->parent != nullptr) ? z->parent->parent->left : nullptr;
                if (y != nullptr && y->isRed) {
                    //left uncle y exists and is red
                    z->parent->isRed = false;
                    y->isRed = false;
                    if (z->parent->parent != nullptr) {
                        //I think this condition is always true, since z->parent is red
                        // (so it is not the root)
                        z->parent->parent->isRed = true;
                    }
                    //violation in subtree fixed up -> the original z is red, its parent is black, the uncle is black and the
                    // grandfather is red ->subtree with grandfather as a root is ok.
                    //the global violation can still exist - if the grandparent was the root and if the grand-grandparent was red
                    z = z->parent->parent;

                } else {
                    //left uncle y does not exist or is black
                    if (z == z->parent->left) {
                        //z is the left children, (z->parent is red)
                        z = z->parent;
                        this->rotateRight(z);
                        //violation is not fixed up - original z is still red and its former parent (now right child) is also red
                        //this is where the root could remain red (because we exit the while loop)
                    } else {
                        //z is the right children (is red), (z->parent is also red)
                        z->parent->isRed = false;
                        z->parent->parent->isRed = true;
                        this->rotateLeft(z->parent->parent);
                        //violation of two red nodes is fixed up. z->parent is now black. grandparent is now left child of parent and is red.
                        //it has to be red because the uncle is black and the other child of parent is black or does not exist
                        //the root of the subtree, the former parent is black - if its the root of the whole tree, then there is no other violations
                    }
                }
            }
        }
        this->root->isRed = false;
    }

    std::string subtreeToString(node *subroot) {
        std::string temp = "";
        if (subroot->left != nullptr) {
            temp =temp+ subtreeToString(subroot->left);
        }
        temp =temp+ std::to_string(subroot->item) + ", ";
        if (subroot->right != nullptr) {
            temp = temp+subtreeToString(subroot->right);
        }
        return temp;
    }
    std::string subtreeToString2(node *subroot) {
        std::string temp = "I am "+std::to_string(subroot->item) + ", ";
        if (subroot->left != nullptr) {
            temp = temp + "my left child is: "+std::to_string(subroot->left->item)+". ";
            //subtreeToString2(subroot->left);
        }
        if (subroot->right != nullptr) {
            temp = temp + "my right child is: "+std::to_string(subroot->right->item)+". ";
            //subtreeToString2(subroot->right);
        }
        temp=temp+"\n\n";
        if (subroot->left != nullptr) {
            //temp = temp + "my left child is: "<<std::to_string(subroot->left->item);
            temp=temp+subtreeToString2(subroot->left);
        }
        if (subroot->right != nullptr) {
            //temp = temp + "my right child is: "<<std::to_string(subroot->right->item);
            temp=temp+subtreeToString2(subroot->right);
        }
        return temp;
    }

    void destructSubtree(node *subroot) {
        if (subroot != nullptr) {
            if (subroot->left != nullptr) {
                destructSubtree(subroot->left);

            }
            if (subroot->right != nullptr) {
                destructSubtree(subroot->right);

            }
            std::cout << "node " << subroot->item << " is being deleted.\n";
            delete subroot;
        }
    }

public:
    RedBlackTree() {
        this->root = nullptr;
    }

    ~RedBlackTree() {
        destructSubtree(this->root);
    }

    std::string toString() {
        return subtreeToString(this->root);
    }
    std::string toString2() {
        return subtreeToString2(this->root);
    }

    void insert(T item) {
        node *newNode = new node;
        newNode->item = item;
        newNode->isRed = true;

        node *temp = this->root;
        node *tempParent = nullptr;
        while (temp != nullptr) {
            tempParent = temp;
            if (item < (temp->item)) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        if (tempParent == nullptr) {
            this->root = newNode;
        } else {
            newNode->parent = tempParent;
            (tempParent->item < newNode->item) ? tempParent->right = newNode : tempParent->left = newNode;
        }
        rebalanceTree(newNode);
    }

};


#endif //CPP_REDBLACKTREE_H
