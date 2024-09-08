#include <iostream>
using namespace std;

class Node{
    int value;
    Node *next;
    
    public:
    Node():value(0),next(NULL){}
    Node(const int v):value(v),next(NULL){}
    friend class SingleyLinkedList;
};

class SingleyLinkedList{
    Node *head;
    public:
    SingleyLinkedList():head(NULL){}
    SingleyLinkedList(Node *n):head(n){}
    
    void InsertNodeAtFront(const int data);
    void InsertNodeAtEnd(const int data);
    void PrintLinkedList();
    void ReverseLinkedList();
};

void SingleyLinkedList::InsertNodeAtEnd(const int data){
    Node *n = new Node(data);
    if (head == NULL){
        head = n;
    }
    else{
        Node *tmp = head;
        while(tmp -> next != NULL){
            tmp = tmp -> next;
        }
    tmp->next = n;
    n->next = NULL;
    }
}

void SingleyLinkedList::PrintLinkedList(){
    Node *tmp = head;
    while(tmp->next != NULL){
        cout<<tmp->value<<"->";
        tmp = tmp->next;
    }
    cout<<tmp->value;
    cout<<"->NULL";
}

void SingleyLinkedList::ReverseLinkedList(){
    Node *ctrPtr = head;
    Node *next = NULL;
    Node *prev = NULL;
    while(ctrPtr != NULL){
        next = ctrPtr->next;
        ctrPtr->next = prev;
        prev = ctrPtr;
        ctrPtr = next;
    }
    head = prev;
}

int main() {
    SingleyLinkedList s;
    int x;
    cout<<"\nEnter the number of nodes you want to form: ";
    cin>>x;
    for(int i=0; i<x; i++){
         s.InsertNodeAtEnd(i+1);
    }
    s.PrintLinkedList();
    s.ReverseLinkedList();
    cout<<"\n";
    s.PrintLinkedList();

    return 0;
}
