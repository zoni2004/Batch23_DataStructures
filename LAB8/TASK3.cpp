#include <iostream>
#include <sstream>
using namespace std;

/* In a stock market analysis application, the profits and losses over time are represented as
nodes in a binary tree. To help investors, you need to identify the maximum profit path
they could have taken at any point in time. */

class Node {
    int data;
    Node *left;
    Node *right;

public:
    Node(int val) : data(val), left(NULL), right(NULL) {}

    friend class BST;
};

class BST {
    Node* root;

    void insert(Node*& root, int value) { 
        if (root == NULL) {
            root = new Node(value);
        } 
        else if (value < root->data) {
            insert(root->left, value);
        } 
        else {
            insert(root->right, value);
        }
    }

    void findMaxPath(Node* root, string path, int &maxSum, string &maxPath) {
        if (root == NULL) {
            return;
        }

        path += to_string(root->data) + " ";

        if (root->left == NULL && root->right == NULL) { 
            int sum = 0;
            stringstream ss(path);
            string token;
            while (ss >> token) {
                sum += stoi(token); 
            }
            
            if (sum > maxSum) {
                maxSum = sum;
                maxPath = path;
            }
        }
        else {
            findMaxPath(root->left, path, maxSum, maxPath);
            findMaxPath(root->right, path, maxSum, maxPath);
        }
    }

    int findMin(Node* root) {
        if (root == NULL) {
            return -1; 
        }
        while (root->left != NULL) { 
            root = root->left;
        }
        return root->data;
    }

public:
    BST() : root(NULL) {}

    void insert(int val) {
        insert(root, val);
    }

    string findMaxPath() {
        int maxSum = 0; 
        string maxPath = "";
        findMaxPath(root, "", maxSum, maxPath);
        return maxPath;
    }
};

int main() {
    BST tree;

    tree.insert(10); 
    tree.insert(5);  
    tree.insert(15);  
    tree.insert(3);  
    tree.insert(7);   
    tree.insert(12);  
    tree.insert(18);  

    cout << "Maximum profit path: ";
    string maxProfitPath = tree.findMaxPath();
    cout << maxProfitPath << endl; 

    return 0;
}
