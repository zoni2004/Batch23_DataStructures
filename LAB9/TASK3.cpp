#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_KEYS 2
#define MAX_CHILDREN 3

struct Node {
    int keys[MAX_KEYS];
    Node* children[MAX_CHILDREN];
    int keyCount;
    bool isLeaf;

    Node(bool leaf) {
        keyCount = 0;
        isLeaf = leaf;
        for (int i = 0; i < MAX_KEYS; i++) keys[i] = 0;
        for (int i = 0; i < MAX_CHILDREN; i++) children[i] = nullptr;
    }
};

void inOrderTraversal(Node* root, int* elements, int& index) {
    if (!root) return;
    if (root->isLeaf) {
        for (int i = 0; i < root->keyCount; i++) elements[index++] = root->keys[i];
    } else {
        for (int i = 0; i < root->keyCount; i++) {
            inOrderTraversal(root->children[i], elements, index);
            elements[index++] = root->keys[i];
        }
        inOrderTraversal(root->children[root->keyCount], elements, index);
    }
}

Node* build23Tree(int* elements, int start, int end) {
    if (start > end) return nullptr;
    if (end - start + 1 <= MAX_KEYS) {
        Node* leaf = new Node(true);
        for (int i = start; i <= end; i++) leaf->keys[leaf->keyCount++] = elements[i];
        return leaf;
    }
    int mid1 = (start + end) / 3;
    int mid2 = (2 * (start + end)) / 3;
    Node* root = new Node(false);
    root->keys[root->keyCount++] = elements[mid1];
    root->keys[root->keyCount++] = elements[mid2];
    root->children[0] = build23Tree(elements, start, mid1 - 1);
    root->children[1] = build23Tree(elements, mid1 + 1, mid2 - 1);
    root->children[2] = build23Tree(elements, mid2 + 1, end);
    return root;
}

Node* merge23Trees(Node* tree1, Node* tree2) {
    int elements[100], index = 0;
    inOrderTraversal(tree1, elements, index);
    inOrderTraversal(tree2, elements, index);
    sort(elements, elements + index);
    index = unique(elements, elements + index) - elements;
    return build23Tree(elements, 0, index - 1);
}

void displayTree(Node* root, int level = 0) {
    if (!root) return;
    for (int i = 0; i < level; i++) cout << "   ";
    for (int i = 0; i < root->keyCount; i++) cout << root->keys[i] << " ";
    cout << endl;
    for (int i = 0; i <= root->keyCount; i++) displayTree(root->children[i], level + 1);
}

int main() {
    Node* tree1 = new Node(false);
    tree1->keys[0] = 10; tree1->keys[1] = 20; tree1->keyCount = 2;
    tree1->children[0] = new Node(true);
    tree1->children[1] = new Node(true);
    tree1->children[2] = new Node(true);
    tree1->children[0]->keys[0] = 5; tree1->children[0]->keyCount = 1;
    tree1->children[1]->keys[0] = 15; tree1->children[1]->keyCount = 1;
    tree1->children[2]->keys[0] = 25; tree1->children[2]->keyCount = 1;

    Node* tree2 = new Node(false);
    tree2->keys[0] = 35; tree2->keys[1] = 40; tree2->keyCount = 2;
    tree2->children[0] = new Node(true);
    tree2->children[1] = new Node(true);
    tree2->children[2] = new Node(true);
    tree2->children[0]->keys[0] = 30; tree2->children[0]->keyCount = 1;
    tree2->children[1]->keys[0] = 38; tree2->children[1]->keyCount = 1;
    tree2->children[2]->keys[0] = 50; tree2->children[2]->keyCount = 1;

    Node* mergedTree = merge23Trees(tree1, tree2);
    displayTree(mergedTree);

    return 0;
}
