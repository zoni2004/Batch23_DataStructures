#include<iostream>
using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

public:
    Node(int val) : data(val), left(NULL), right(NULL) {}
    friend class BST;
};

class BST {
    Node *root;

    Node* sortedArrayToBST(int* arr, int start, int end) {
        if (start > end) {
            return NULL;
        }

        int mid = start + (end - start) / 2;
        Node* node = new Node(arr[mid]);

        node->left = sortedArrayToBST(arr, start, mid - 1);
        node->right = sortedArrayToBST(arr, mid + 1, end);

        return node;
    }

    void inorderTraverse(Node *root) {
        if (root == NULL) {
            return;
        }
        inorderTraverse(root->left);
        cout << root->data << " ";
        inorderTraverse(root->right);
    }

public: 
    BST() : root(NULL) {}

    void convertArrToTree(int *arr, int size) {
        root = sortedArrayToBST(arr, 0, size - 1);
    }

    void inorderTraverse() {
        inorderTraverse(root);
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    BST bst;
    bst.convertArrToTree(arr, size);

    cout << "Inorder Traversal of the Balanced BST: ";
    bst.inorderTraverse();
    cout << endl;

    return 0;
}
