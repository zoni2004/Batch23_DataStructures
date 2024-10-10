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

//will reverse the infix expression
string reverse(string expression, int size){
    Stack s(size);
    string reverse = "";

    for(int i=0; i<size; i++){
        if(s.peek() == '('){
            s.pop();
            reverse += ')';
        }
        else if(s.peek() == ')'){
            s.pop();
            reverse += '(';
        }
        else{
            reverse+=s.peek();
            s.pop();
        }
    }
}
string convertingInfixtoPrefix(string expression, int size){
    Stack s(size);
    string prefix = "";

    expression = reverse(expression, size);
    for(int i = 0; i < size; i++){
        char current = expression[i];

        if((current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9') || (current >= 'a' && current <= 'z')){
            prefix += current;
        }
       
        else if(current == '('){
            s.push(current);
        }
      
        else if(current == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                prefix += s.pop();
            }
            s.pop(); 
        }
        
        else{
            //rather than popping operators with greater or equal we only check greater
            while(!s.isEmpty() && precedence(current) < precedence(s.peek())){
                if(precedence(current) == precedence(s.peek()) && associativity(current) == 'L'){
                    prefix += s.pop();
                } 
                else {
                    break; 
                }
            }
            s.push(current); 
        }
    }

    while(!s.isEmpty()){
        prefix += s.pop();
    }

    prefix = reverse(prefix, size);
    
    return prefix;
}

int main(){
    string expression = "K+L-M*N+(O^P)*W/U/V*T+Q";
    int size = expression.length();
    cout << "\nThe postfix of the infix expression \"" << expression << "\" is: " << convertingInfixtoPrefix(expression, size) << endl;

    return 0;
}
