//
// Created by mwasilewski on 30.11.18.
//

#ifndef CPP_BINARYSEARCHTREE_H
#define CPP_BINARYSEARCHTREE_H

#include "Comparable.h"

template<class T>
class BinarySearchTree {
    struct node {
        node *left;
        node *right;
        node *parent;
        T item;
    };
private:
    node *root;

    void destroy_sub_tree(node *n) {
        if (n != NULL) {
            destroy_sub_tree(n->left);
            destroy_sub_tree(n->right);
            std::cout << "Deleting node " << n->item<<"\n";
            delete n;
        }

    }

public:
    BinarySearchTree() {
        this->root = NULL;
    }


    virtual ~BinarySearchTree() {
        if (this->root != NULL) {
            destroy_sub_tree(this->root);
        }
    }

    void inorder_tree_walk(node *temp) {
        if (temp != NULL) {
            inorder_tree_walk(temp->left);
            std::cout <<temp->item;
            std::cout<<std::endl;
            inorder_tree_walk(temp->right);

        }

    }

    void inorder_tree_walk() {
        inorder_tree_walk(this->root);
    }

    node *search(node *temp, T key) {

        if (temp == NULL) {
            return NULL;
        }

        if ((int) key == (int) temp->item) {
            return temp;
        }


        if ((int) key < (int) temp->item) {
            return search(temp->left, key);

        } else {
            return search(temp->right, key);
        }
    }

    T search(T key) {
        node * x=search(this->root, key);
        return (x!=NULL)? x->item:NULL;
    }

    node *min(node *temp) {
        if (temp == NULL) {
            return NULL;
        }

        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    node *min() {
        return min(this->root);
    }

    node *max(node *temp) {
        if (temp == NULL) {
            return NULL;
        }

        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }

    node *max() {
        return max(this->root);
    }

    node *successor(node *temp) {
        if (temp == NULL) {
            return NULL;
        }
        if (temp->right != NULL) {
            return this->min(temp->right);
        } else if (temp->parent != NULL) {
            node *temp2 = temp;
            while (temp2->parent != NULL) {
                if (temp2->parent->left == temp2) {
                    return temp2;
                }
                temp2 = temp2->parent;
            }
//            return NULL;
        }

//        temp is the maximum
        return NULL;
    }

    node *predecessor(node *temp) {
        if (temp == NULL) {
            return NULL;
        }
        if (temp->left != NULL) {
            return this->max(temp->left);
        } else if (temp->parent != NULL) {
            node *temp2 = temp;
            while (temp2->parent != NULL) {
                if (temp2->parent->right == temp2) {
                    return temp2;
                }
                temp2 = temp2->parent;
            }
//            return NULL;
        }

//        temp is the minimum
        return NULL;
    }

    void insert(T item) {
        node *temp = this->root;
        if (root == NULL) {
            this->root = new node;
            this->root->item = item;
            this->root->parent = NULL;
            this->root->left = NULL;
            this->root->right = NULL;
        } else {
            bool flag = true;
            while (flag) {
                if (temp->item > item) {
                    if (temp->left == NULL) {
                        flag = false;
                        temp->left = new node;
                        temp->left->item = item;
                        temp->left->parent = temp;
                        temp->left->left = NULL;
                        temp->left->right = NULL;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == NULL) {
                        flag = false;
                        temp->right = new node;
                        temp->right->item = item;
                        temp->right->parent = temp;
                        temp->right->left = NULL;
                        temp->right->right = NULL;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    void delete_node(T key) {
        node *n = search(root,key);
        //std::cout<<n<<std::endl;
        if (n != NULL) {
            if (n->left == NULL && n->right == NULL) {
                std::cout<<"Both children null"<<std::endl;
                if (n->parent != NULL) {
                    if (n->parent->left == n) {
                        n->parent->left = NULL;
                    } else {
                        n->parent->right = NULL;
                    }
                }
            } else {
                if (n->left == NULL) {
                    //std::cout<<"Left child null"<<std::endl;
                    if (n->parent != NULL) {
                        n->right->parent = n->parent;
                        if (n->parent->left == n) {
                            n->parent->left = n->right;
                        } else {
                            n->parent->right = n->right;
                        }
                    } else {
                        this->root = n->right;
                        n->parent = NULL;
                    }
                } else if (n->right == NULL) {
                    //::cout<<"Right child null"<<std::endl;
                    if (n->parent != NULL) {
                        n->left->parent = n->parent;
                        if (n->parent->left == n) {
                            n->parent->left = n->left;
                        } else {
                            n->parent->right = n->left;
                        }
                    } else {

                        this->root = n->left;
                        n->parent = NULL;
                    }
                } else {
                    //std::cout<<"Both children not null"<<std::endl;
                    node *succ = this->successor(n);
                    //std::cout<<succ<<std::endl;
                    //std::cout<<succ->parent<<std::endl;


                    n->right->parent = succ;
                    succ->right = n->right;
                    n->left->parent = succ;
                    succ->left = n->left;
                    if (succ->parent->left ==succ) {
                        succ->parent->left = NULL;

                    } else {
                        succ->parent->right = NULL;
                    }
                    if (n->parent == NULL) {
                        //std::cout<<"n is the root"<<std::endl;
                        this->root = succ;
                        succ->parent = NULL;
                    } else {
                        if (n->parent->left == n) {
                            n->parent->left = succ;

                        } else {
                            n->parent->right = succ;
                        }
                        succ->parent = n->parent;
                    }
                }
            }
            delete n;
        }

    }

};


#endif //CPP_BINARYSEARCHTREE_H
