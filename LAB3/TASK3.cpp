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
    void SegregateList();
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

void SingleyLinkedList::SegregateList(){
    Node *evenStart = NULL;
    Node *evenEnd = NULL;
    Node *oddStart = NULL;
    Node *oddEnd = NULL;
    Node *ctrPtr = head;

    while (ctrPtr != NULL) {
        if (ctrPtr->value % 2 == 0) { 
            if (evenStart == NULL) {
                evenStart = ctrPtr;
                evenEnd = evenStart;
            } 
            else {
                evenEnd->next = ctrPtr;
                evenEnd = evenEnd->next;
            }
        }
        else { 
            if (oddStart == NULL) {
                oddStart = ctrPtr;
                oddEnd = oddStart;
            } 
            else {
                oddEnd->next = ctrPtr;
                oddEnd = oddEnd->next;
            }
        }
        ctrPtr = ctrPtr->next;
    }

    if (evenEnd != NULL) {
        evenEnd->next = oddStart; 
    }

    if (oddEnd != NULL) {
        oddEnd->next = NULL; 
    }

    head = evenStart; 
}

int main() {
    SingleyLinkedList s;
    int x;
    cout<<"\nEnter the number of nodes you want to form: ";
    cin>>x;
    for(int i=0; i<x; i++){
        int element;
        cout<<"\nEnter the value in the node "<<i+1<<"\n";
        cin>>element;
        s.InsertNodeAtEnd(element);
    }
    
    s.PrintLinkedList();
    
    s.SegregateList();
    cout<<"\n";
    s.PrintLinkedList();
    
    return 0;
}
