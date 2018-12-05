package com.example;

import sun.reflect.generics.tree.Tree;

class BinarySearchTree<T extends Comparable<T>> {
    private class TreeNode {
        TreeNode parent = null;
        TreeNode left = null;
        TreeNode right = null;
        T item;
    }

    private TreeNode root;

    private TreeNode minimum2(TreeNode node) {
        if (node == null) {
            return null;
        }
        TreeNode temp = node;
        while (temp.left != null) {
            temp = temp.left;
        }
        return temp;
    }

    public T minimum() {
        return minimum2(this.root).item;
    }

    private TreeNode maximum2(TreeNode node) {
        if (node == null) {
            return null;
        }
        TreeNode temp = node;
        while (temp.right != null) {
            temp = temp.right;
        }
        return temp;
    }

    public T maximum() {
        return maximum2(this.root).item;
    }

    private TreeNode search2(T key) {
        if (this.root == null) {
            return null;
        }
        TreeNode temp = this.root;
        while (true) {
            if (key == temp.item) {
                return temp;
            }
            if (key.compareTo(temp.item) < 0) {
                if (temp.left == null) {
                    return null;
                } else {
                    temp = temp.left;
                }
            } else {
                if (temp.right == null) {
                    return null;
                } else {
                    temp = temp.right;
                }
            }
        }
    }

    public T search(T key) {
        return search2(key).item;
    }

    public void insert(T key) {
        TreeNode new_item = new TreeNode();
        new_item.item = key;
        if (this.root == null) {
            this.root = new_item;
        } else {
            TreeNode temp = this.root;
            while (true) {
                if (new_item.item.compareTo(temp.item) < 0) {
                    if (temp.left == null) {
                        temp.left = new_item;
                        new_item.parent = temp;
                        break;
                    } else {
                        temp = temp.left;
                    }
                } else {
                    if (temp.right == null) {
                        temp.right = new_item;
                        new_item.parent = temp;
                        break;
                    } else {
                        temp = temp.right;
                    }
                }
            }
        }
    }

    private TreeNode successor2(TreeNode node) {
        if (node.right != null) {
            return maximum2(node.right);
        } else {
            TreeNode temp = node;
            while (temp.parent != null) {
                if (temp.parent.left == temp) {
                    break;
                } else {
                    temp = temp.parent;
                }
            }
            return temp.parent;
        }
    }

    public T successor(T key) {
        TreeNode temp = search2(key);
/*        System.out.println("temp item: " + temp.item.toString());
        System.out.println("temp right: " + temp.right);
        System.out.println("temp left: " + temp.left);*/
        if (temp == null) {
            return null;
        }
        temp=successor2(temp);
        return (temp==null)?null:temp.item;
    }

    private String in_order_walk(TreeNode node) {
        if (node == null) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        sb.append(this.in_order_walk(node.left));
        sb.append(node.item.toString() + ", ");
        sb.append(this.in_order_walk(node.right));
        return sb.toString();
    }

    @Override
    public String toString() {
        return in_order_walk(this.root);
    }

}