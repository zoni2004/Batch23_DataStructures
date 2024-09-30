#include<iostream>
using namespace std;

class Stack{
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
    
    void printStack() {
	    while (!isEmpty()) {
		    cout << peek() << " ";
			pop();
        }
        cout << endl;
}
};

int main(){
	Stack stack(10);  
    Stack even(10);
    Stack odd(10);
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6); 
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.push(10);
  
     while (!stack.isEmpty()) {
        int item = stack.pop(); 
        if (item % 2 == 0) {
            even.push(item); 
        } else {
            odd.push(item); 
        }
    }

    cout << "Even stack contents: ";
    even.printStack();

    cout << "Odd stack contents: ";
    odd.printStack();
}
