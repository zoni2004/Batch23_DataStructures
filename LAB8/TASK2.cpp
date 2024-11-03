#include<iostream>
#include <stack>
using namespace std;

/*Given a binary tree, write an algorithm to print its nodes in zigzag order. That is, the first
level should be printed from left to right, the second level from right to left, and alternate
this pattern level by level.*/

class Node{
    int data;
    Node *left;
    Node *right;

    public:
    Node(int val):data(val),left(NULL),right(NULL){}

    friend class BST;
};

class BST{
    Node *root;

    void insert(Node *&root, int value){
        Node *n = new Node(value);

        if(root == NULL){
            root = n;
        }
        else if(root->data < value){
            insert(root->right, value);
        }
        else{
            insert(root->left, value);
        }
    }

    void printZigzag() {
        if (root == NULL){
            return;
        }
        
        stack <Node*> currentLevel;
        stack <Node*> nextLevel;
        
        currentLevel.push(root);
        bool leftToRight = true;
        
        while(!currentLevel.empty()){
            Node *currentNode = currentLevel.top();
            currentLevel.pop();
            
            cout << currentNode->data << " ";
            
            if (leftToRight) {
                if (currentNode->left){
                    nextLevel.push(currentNode->left);
                } 
                if (currentNode->right) {
                    nextLevel.push(currentNode->right);
                }
            }
            else {
                if (currentNode->right) {
                    nextLevel.push(currentNode->right);
                }
                if (currentNode->left){
                    nextLevel.push(currentNode->left);
                }
            }

            if (currentLevel.empty()) {
                swap(currentLevel, nextLevel);
                leftToRight = !leftToRight; 
            }
        cout << " ";
        } 
    }
    
    public:
    BST():root(NULL){}

    void insert(int val){
        insert(root, val);
    }

    void printZigZag(){
        printZigzag();
    }
};

int main(){
    BST tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "Zigzag order traversal of the tree:\n";
    tree.printZigZag(); 

    return 0;
}
