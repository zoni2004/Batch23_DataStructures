#include <iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    
    public:
    Node(int value):data(value),next(NULL){}
    friend class SingleyLinkedList;
};

class SingleyLinkedList{
    Node *head;
    
    public:
    SingleyLinkedList():head(NULL){}
    
    //populating the linked list
    void addAtEnd(int value){
        Node* tmp = head;
        Node* n = new Node(value);
        if(head == NULL){
            head = n;
        }
        else{
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            tmp->next = n;
        }
    }
    
    //printing the linked list
    void print(){
        Node *tmp = head;
        while(tmp != NULL){
            cout<<tmp->data<<"->";
            tmp = tmp->next;
        }
        cout<<" NULL\n";
    }
    
    //reversing linked list recursively
    Node* recursiveReverse(Node *head){
        Node *tmp = head;
        Node* prev = NULL;
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* newHead = recursiveReverse(head->next);
        head->next->next = head; 
        head->next = NULL; 
        return newHead;
    }
    
    void reverse() {
        head = recursiveReverse(head);
    }
};

int main() {
    SingleyLinkedList s;
    int x;
    cout<<"\nEnter the number of nodes you want to form: ";
    cin>>x;
    for(int i=0; i<x; i++){
        int element;
        cout<<"\nEnter the value in the node "<<i+1<<"\n";
        cin>>element;
        s.addAtEnd(element);
    }
    s.print();
    s.reverse();
    s.print();

    return 0;
}
