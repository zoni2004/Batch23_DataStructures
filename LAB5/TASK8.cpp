#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
        cout << item << " pushed to stack" << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Unable to pop" << endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << stack.peek() << " is at the top of the stack" << endl;

    cout << stack.pop() << " popped from stack" << endl;
    cout << stack.pop() << " popped from stack" << endl;

    cout << stack.peek() << " is at the top of the stack" << endl;

    return 0;
}
