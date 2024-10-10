#include<iostream>
using namespace std;

class Stack{
    int top;
    int capacity;
    char *arr;

public:
    Stack(int capacity){
        top = -1;
        this->capacity = capacity;
        arr = new char[capacity];
    }

    bool isFull(){
        return top == capacity - 1;
    }

    bool isEmpty(){
        return top == -1;
    }

    void resize(int newCapacity){
        char *newArr = new char[newCapacity]; 
        for(int i = 0; i <= top; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

    void push(char value){
        if(isFull()){
            resize(capacity + 1); 
        }
        arr[++top] = value;
    }

    char pop(){
        if(isEmpty()){
            cout << "Stack underflow\n";
            return '\0'; 
        }
        return arr[top--];
    }

    char peek(){
        if(isEmpty()){
            return '\0'; 
        }
        return arr[top];
    }
};

char associativity(char operant){
    if(operant == '^'){
        return 'R'; 
    }
    return 'L'; 
}

int precedence(char operant){
    if(operant == '^'){
        return 3;
    } else if(operant == '/' || operant == '*'){
        return 2;
    } else if(operant == '+' || operant == '-'){
        return 1;
    }
    return -1; 
}

string convertingInfixtoPostfix(string expression, int size){
    Stack s(size);
    string postfix = "";

    for(int i = 0; i < size; i++){
        char current = expression[i];

        if((current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9') || (current >= 'a' && current <= 'z')){
            postfix += current;
        }
       
        else if(current == '('){
            s.push(current);
        }
      
        else if(current == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                postfix += s.pop();
            }
            s.pop(); 
        }
        
        else{
            while(!s.isEmpty() && precedence(current) <= precedence(s.peek())){
                if(precedence(current) == precedence(s.peek()) && associativity(current) == 'L'){
                    postfix += s.pop();
                } 
                else {
                    break; 
                }
            }
            s.push(current); 
        }
    }

    while(!s.isEmpty()){
        postfix += s.pop();
    }

    return postfix;
}

int main(){
    string expression = "K+L-M*N+(O^P)*W/U/V*T+Q";
    int size = expression.length();
    cout << "\nThe postfix of the infix expression \"" << expression << "\" is: " << convertingInfixtoPostfix(expression, size) << endl;

    return 0;
}
