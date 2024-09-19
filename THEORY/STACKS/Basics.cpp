#include <iostream>
using namespace std;

class Stack{
    int top;
    int *arr;
    int maxSize;
    
    public:
    Stack(int size=1){
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }
    
    ~Stack(){
        delete [] arr;
    }
    
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    
    void resize(int newMaxSize){
        int *newArr = new int[newMaxSize];
        for(int i=0; i<=top; i++){
            newArr[i] = arr[i];
        }
        delete [] arr;
        arr = newArr;
        maxSize = newMaxSize;
    }
    
    void push(int x){
        if(top > maxSize-1){
            resize(maxSize+1);
        }
        else{
            arr[++top] = x;
        }
    }
    
    int pop(){
        if(top == -1){
            cout<<"Stack underflow";
            return -1;
        }
        else{
            return arr[top--];
        }
    }
    
    int peek(){
        if(top == -1){
            cout<<"stack underflow";
            return -1;
        }
        else{
            return arr[top];
        }
    }
    
    int getSize(){
        return top+1;
    }
};

int main() {
    Stack s;
    cout<<"\nBefore adding elements the capacity is: "<<s.getSize();
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"\nAfter adding elements the capacity is: "<<s.getSize();
    
    return 0;
}
