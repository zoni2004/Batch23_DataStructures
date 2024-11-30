#include <iostream>
#include <queue>
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

void levelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();

            for (int j = 0; j < node->keyCount; j++) {
                cout << node->keys[j] << " ";
            }

            if (!node->isLeaf) {
                for (int j = 0; j <= node->keyCount; j++) {
                    if (node->children[j]) {
                        q.push(node->children[j]);
                    }
                }
            }
        }
        cout << endl; // Move to the next level
    }
}

int main() {
    Node* root = new Node(false);
    root->keys[0] = 10; root->keys[1] = 20; root->keyCount = 2;
    root->children[0] = new Node(true);
    root->children[1] = new Node(true);
    root->children[2] = new Node(true);
    root->children[0]->keys[0] = 5; root->children[0]->keyCount = 1;
    root->children[1]->keys[0] = 15; root->children[1]->keyCount = 1;
    root->children[2]->keys[0] = 25; root->children[2]->keyCount = 1;

    cout << "Level-order traversal of the 2-3 tree:" << endl;
    levelOrderTraversal(root);

    return 0;
}
