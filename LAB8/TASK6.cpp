#include <iostream>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;

public:
    Node(int val) : data(val), left(NULL), right(NULL) {}
    friend class BST;
};

class BST {
    Node* root;

    Node* insert(Node* root, int val) {
        if (root == NULL) {
            return new Node(val);
        }
        if (val < root->data) {
            root->left = insert(root->left, val);
        } else if (val > root->data) {
            root->right = insert(root->right, val);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void swapValues(Node* node1, Node* node2) {
        if (node1 && node2) {
            int temp = node1->data;
            node1->data = node2->data;
            node2->data = temp;
        }
    }


    void findSwappedNodes(Node* root, Node*& first, Node*& middle, Node*& last, Node*& prev) {
        if (root == NULL) {
            return;
        }

        findSwappedNodes(root->left, first, middle, last, prev);

        if (prev && prev->data > root->data) {
            if (!first) {
                first = prev;
                middle = root;
            } 
            else {
                last = root;
            }
        }


        prev = root;

        findSwappedNodes(root->right, first, middle, last, prev);
    }

public:
    BST() : root(NULL) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void swapNodes(int a, int b) {
        Node* nodeA = searchNode(root, a);
        Node* nodeB = searchNode(root, b);
        swapValues(nodeA, nodeB);
    }

    Node* searchNode(Node* root, int a) {
        if (root == NULL) return NULL;
        if (root->data == a) return root;
        if (a < root->data) return searchNode(root->left, a);
        return searchNode(root->right, a);
    }

    void recoverTree() {
        Node *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

        findSwappedNodes(root, first, middle, last, prev);

        if (first && last) {
            swapValues(first, last);
        } else if (first && middle) {
            swapValues(first, middle);
        }
    }
};

int main() {
    BST bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(8);
    bst.insert(2);
    bst.insert(20);
    bst.insert(15);
    bst.insert(30);

    cout << "Inorder Traversal before fixing BST: ";
    bst.inorder();

    bst.swapNodes(8, 20);  

    cout << "Inorder Traversal after swapping nodes 8 and 20: ";
    bst.inorder();

    bst.recoverTree();

    cout << "Inorder Traversal after recovering BST: ";
    bst.inorder();

    return 0;
}
