#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Node {
    int data;
    int height;
    Node *left;
    Node *right;

public:
    Node(int val) : data(val), left(NULL), right(NULL) {
        height = 1;
    }

    friend class AVL;
};

class AVL {
    Node *root;
    int rotations;

    int getHeight(Node *node) {
        if (node == NULL) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node *node) {
        if (node == NULL) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node *LL(Node *node) {
        Node *child = node->left;
        node->left = child->right;
        child->right = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

        rotations++; 
        return child;
    }

    Node *RR(Node *node) {
        Node *child = node->right;
        node->right = child->left;
        child->left = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

        rotations++; 
        return child;
    }

    Node* insert(Node *node, int val) {
        if (node == NULL) {
            return new Node(val);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        else if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else {
            return node;
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalanceFactor(node);

        if (balance > 1 && val < node->left->data) {
            return LL(node);
        }
        if (balance < -1 && val > node->right->data) {
            return RR(node);
        }
        if (balance > 1 && val > node->left->data) {
            node->left = RR(node);
            return LL(node);
        }
        if (balance < -1 && val < node->right->data) {
            node->right = LL(node);
            return RR(node);
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

public:
    AVL() : root(NULL), rotations(0) {}

    void insert(int val) {
        root = insert(root, val);  
    }

    void print() {
        inorderTraversal(root);
        cout << endl;
    }

    int getRotations() {
        int totalRotations = rotations;  
        rotations = 0;  
        return totalRotations;
    }
};

int main() {
    AVL tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);

    cout << "In-order traversal of AVL tree: ";
    tree.print();

    cout << "The total number of rotations performed: " << tree.getRotations() << endl;

    return 0;
}
