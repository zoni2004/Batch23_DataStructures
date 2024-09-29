#include <iostream>
using namespace std;

class Stack {
private:
    int top;        
    int capacity;  
    int* array;     

public:
    Stack(int size) {
        capacity = size; 
        top = -1;        
        array = new int[capacity]; 
    }

    ~Stack() {
        delete[] array; 
    }

    void push(int item) {
        if (isFull()) {
            cout << "Stack overflow! Unable to push " << item << endl;
            return;
        }
        array[++top] = item; 
        cout << item << " pushed to stack" << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Unable to pop" << endl;
            return -1; 
        }
        return array[top--]; 
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return array[top]; 
    }

    bool isEmpty() {
        return top == -1; 
    }
    bool isFull() {
        return top == capacity - 1; 
    }
};

int main() {
    Stack stack(5); 

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60); 

    cout << stack.peek() << " is at the top of the stack" << endl; 

    cout << stack.pop() << " popped from stack" << endl; 
    cout << stack.pop() << " popped from stack" << endl; 

    cout << stack.peek() << " is at the top of the stack" << endl; 

    return 0;
}
