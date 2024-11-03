#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    return (root1->data == root2->data &&
            isIdentical(root1->left, root2->left) &&
            isIdentical(root1->right, root2->right));
}

bool isSubtree(Node* T1, Node* T2) {
    if (T2 == NULL) {
        return true;
    }
    if (T1 == NULL) {
        return false;
    }
    if (isIdentical(T1, T2)) {
        return true;
    }
    return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
}

int main() {
    Node* T1 = new Node(1);
    T1->left = new Node(2);
    T1->right = new Node(3);
    T1->left->left = new Node(4);
    T1->left->right = new Node(5);
    T1->right->left = new Node(6);
    T1->right->right = new Node(7);

    Node* T2 = new Node(3);
    T2->left = new Node(6);
    T2->right = new Node(7);

    if (isSubtree(T1, T2)) {
        cout << "T2 is a subtree of T1" << endl;
    } else {
        cout << "T2 is not a subtree of T1" << endl;
    }

    return 0;
}
