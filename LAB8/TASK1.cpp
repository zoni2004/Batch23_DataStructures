#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;

/*You are working on a network application that needs to send the structure of a binary tree
over a network. The tree should be converted to a string for transmission and
reconstructed at the receiver's end.*/

class Node{
    int data;
    Node *left;
    Node *right;

    public:
    Node(int value):data(value),left(NULL),right(NULL){}

    friend class BT;
};

class BT{
    Node *root;

    void insert(Node *&root, int value){
        if(root == NULL){
           root = new Node(value);
        }
        else if(root->left == NULL){
            insert(root->left, value);
        }
        else if(root->right == NULL){
            insert(root->right, value);
        }
        else{
            insert(root->left, value);
        }
    }

    void inorder(Node* root) {
        if (root == NULL){
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
        
    }

    string conversion(Node *root){
        string path = " ";
        if (root == NULL) {
            path += "# ";
            return path;
        }

        path = to_string(root->data) + " ";
        path += conversion(root->left);
        path += conversion(root->right);

    return path;
    }

    public:
    BT():root(NULL){}

    void insert(int val){
        insert(root, val);
    }

    void inorder(){
        inorder(root);
    }

    string conversion(){
        return conversion(root);
    }

    Node* reconstruction(stringstream &ss){
        string token;
        if (!(ss >> token)){
            return NULL;
        }

        if (token == "#") {
            return NULL; 
        }

        Node* node = new Node(stoi(token)); 
        node->left = reconstruction(ss); 
        node->right = reconstruction(ss); 

        return node;
    }
    
    void setRoot(Node* newRoot) {
        root = newRoot;
    }

};
int main(){
     BT tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

    cout << "\nInorder traversal of the tree: ";
    tree.inorder();

     string serialized = tree.conversion();
    cout << "\nTree structure in serialized form: " << serialized << endl;

    stringstream ss(serialized);
    Node* reconstructedTree = tree.reconstruction(ss); 

    BT reconstructed;
    reconstructed.setRoot(reconstructedTree); 

    cout << "\nInorder traversal of the reconstructed tree: ";
    reconstructed.inorder();

    return 0;
}
