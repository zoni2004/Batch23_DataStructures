#include <iostream>
using namespace std;

class Node{
    int value;
    Node *next;

    public:
    Node(int value){
        this->value = value;
        next = NULL;
    }

    friend class Queue;
};

class Queue{
    Node *front;
    Node *rear;

    public:
    Queue():front(NULL),rear(NULL){}

    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int value){
        Node *n = new Node(value);
        if(isEmpty()){
            rear = n;
            front = n;
        }
        else{
             rear->next = n;
             rear = n;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"\nQueue underflow";
        }
        else{
            Node *tmp = front;
            front = front->next;
            if(front == NULL){
                rear = NULL;
            }

            delete tmp;
        }
    }

    int getFront(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return -1;
        }
        else{
            return front->value;
        }
    }

    void print(){
        Node* tmp = front;
        while(tmp != rear){
            cout<<tmp->value<<"->";
            tmp = tmp->next;
        }
        cout<<rear->value<<"->NULL";
    }

};

int main(){
    Queue q;
    
    for (int i = 1; i <= 10; i++) {
        q.enqueue(i);
    }
    q.print();

    cout << "\nRemoving 5 people\n";
    for (int i = 0; i < 5; i++) {
        q.dequeue();
        cout<<"\n";
        q.print();
    }

    cout << "\nAttempting to add more people\n";
    for (int i = 11; i <= 15; i++) {
        q.enqueue(i);
        cout<<"\n";
        q.print();
    }
    
    return 0;
}
