#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

public:
    Node(int val) : data(val), left(NULL), right(NULL) {}
    friend class AVL;
};

class AVL {
    Node *root;

    Node *insert(Node *node, int val) {
        if (node == NULL) {
            return new Node(val);
        }
        if (val > node->data) {
            node->right = insert(node->right, val);
        } else if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            return node; 
        }
        return node;
    }

    void inorderTraversal(Node *node) {
        if (node == NULL) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    int getHeight(Node *node) {
        if (node == NULL) {
            return 0;
        }
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    bool checkBST(Node *root){
        if(root == NULL){
            return true;
        }
        bool flag = false;
        if(root->data < root->right->data && root->data > root->left->data && balanced(root->left) && balanced(root->right)){
            flag = true;
        }
        if(flag){
            return true;
        }
    return false;
    }

    bool balanced(Node *root){
        if(root == NULL){
            return true;
        }
        bool flag = false;
        if(abs(getHeight(root->left)-getHeight(root->right)) <= 1 && balanced(root->left) && balanced(root->right)){
            flag = true;
        }
        if(flag){
            return true;
        }
    return false;
    }


public:
    AVL() : root(NULL) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void print() {
        inorderTraversal(root);
        cout << endl;
    }

    bool isAVL(Node *node) {
        return checkBST(node) && balanced(node);
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    AVL tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(15);
    tree.insert(17);

    cout << "In-order traversal of AVL tree: ";
    tree.print();

    if (tree.isAVL(tree.getRoot())) {
        cout << "The tree is a valid AVL tree." << endl;
    } else {
        cout << "The tree is not a valid AVL tree." << endl;
    }
    return 0;
}
