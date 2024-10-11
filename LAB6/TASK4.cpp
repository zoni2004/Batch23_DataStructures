#include <iostream>
using namespace std;

class Stack{
    int top;
    int capacity;
    int *arr;

    public:
    Stack(int capacity){
        top = -1;
        this->capacity = capacity;
        arr = new int [capacity];
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
    return false;
    }

    bool isFull(){
        if(top == capacity-1){
            return true;
        }
    return false;
    }

    void resize(int newCapacity){
        int *newArr = new int [capacity];
        for(int i=0; i<=top; i++){
            newArr[i] = arr[i];
        }
        delete [] arr;
        arr = newArr;
        capacity = newCapacity;
    }

    void push(int value){
        if(isFull()){
            resize(capacity+1);
        }
        else{
            arr[++top] = value;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"\nStack underflow";
            return -1;
        }
        else{
            return arr[top--];
        }
    }

    int peek(){
        if(isEmpty()){
            cout<<"\nStack underflow";
            return -1;
        }
        else{
            return arr[top];
        }
    }
};

class Queue{
    Stack s1, s2;
    int capacity;
    
    public:
    Queue(int capacity):s1(capacity),s2(capacity){
        this->capacity = capacity;
    }

    void enqueue(int value){
        while(!s1.isEmpty()){
            s2.push(s1.pop());
        }
         s1.push(value);
        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }
    }

    int dequeue(){
        if(s1.isEmpty()){
            cout<<"Stack underflow";
            return -1;
        }
        else{
            return s1.pop();
        }
    }

    int front(){
        if(s1.isEmpty()){
            cout<<"Stack is empty";
            return -1;
        }
        else{
            return s1.peek();
        }
    }
};

int main(){
    Queue q(3); 
	q.enqueue(3); 
	q.enqueue(4); 
	q.enqueue(5); 
	
	cout<<q.front()<<"\n";
	cout << q.dequeue() << endl; 
	cout << q.dequeue() << endl; 
	cout << q.dequeue() << endl; 


}
