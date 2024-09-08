#include <iostream>
using namespace std;

class Node{
    int value;
    Node *next;
    Node *prev;
    
    public:
    Node():value(0),next(NULL),prev(NULL){}
    Node(const int v):value(v),next(NULL),prev(NULL){}
    friend class DoublyLinkedList;
};

class DoublyLinkedList{
    Node *head;
    Node *tail;
    
    public:
    DoublyLinkedList():head(NULL),tail(NULL){}
    
    void InsertNodeAtFront(const int data);
    void InsertNodeAtEnd(const int data);
    void InsertNodeBeforeGivenVal(const int data, const int location);
    void InsertNodeAfterGivenVal(const int data, const int location);
    void DelHeadNode();
    void DelTailNode();
    void DelParticularNode(const int data);
    void PrintLinkedList();
};

void DoublyLinkedList::InsertNodeAtFront(const int data){
    Node *n = new Node(data);
    if(head == NULL){
        head = n;
        tail = n;
    }
    else{
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void DoublyLinkedList::InsertNodeAtEnd(const int data){
    Node *n = new Node(data);
    if(head == NULL){
        head = n;
        tail = n;
    }
    else{
        n->prev = tail;
        n->next = NULL;
        tail->next = n;
        tail = n;
    }
}

void DoublyLinkedList::InsertNodeBeforeGivenVal(const int data, const int location){
    if(head == NULL){
        cout<<"\nThe list is empty\n";
        return;
    }
    else{
        Node *n = new Node(data);
        Node *tmp = head;
        if(head->value == location){
            InsertNodeAtFront(data);
            return;
        }
        while(tmp->value != location){
            tmp = tmp->next;
        }
        if (tmp == NULL) {
        cout << "Node with value " << location << " not found" << "\n";
        delete n; 
        return;
        }
        n->next = tmp;
        n->prev = tmp->prev;
        if (tmp->prev != NULL) {
            tmp->prev->next = n;
        }
        tmp->prev = n;
    }
}

void DoublyLinkedList::InsertNodeAfterGivenVal(const int data, const int location){
    if(head == NULL){
        cout<<"\nThe list is empty\n";
        return;
    }
    else{
        Node *n = new Node(data);
        Node *tmp = head;
        if(tail->value == location){
            InsertNodeAtEnd(data);
            return;
        }
        while(tmp->value != location){
            tmp = tmp->next;
        }
        if (tmp == NULL) {
        cout << "Node with value " << location << " not found" << "\n";
        delete n; 
        return;
        }
        n->next = tmp->next;
        n->prev = tmp;
        if (tmp->next != NULL) {
            tmp->next->prev = n;
         }
        tmp->next = n;
        if (n->next == NULL) {
            tail = n; 
        }
    }
}

void DoublyLinkedList::DelHeadNode(){
    if(head == NULL){
        cout<<"\nThe list is empty\n";
        return;
    }
    Node *tmp = head;
    if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
    }
    delete tmp;
}

void DoublyLinkedList::DelTailNode(){
    if(head == NULL){
        cout<<"\nThe list is empty\n";
        return;
    }
    else{
        Node *tmp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete tmp;
    }
}

void DoublyLinkedList::DelParticularNode(const int data){
    if(head == NULL){
        cout<<"\nThe list is empty\n";
        return;
    }
    else{
        if(head == tail || head->value == data){
            DelHeadNode();
        }
        else if(tail->value == data){
            DelTailNode();
        }
        else{
            Node *tmp = head;
            while(tmp->value != data){
                tmp = tmp->next;
            }
            if(tmp == NULL){
                cout<<"Node with value " << data << " not found" << "\n";
                delete tmp; 
                return;
            }
            tmp->prev->next = tmp->next;
            if (tmp->next != NULL) {
                tmp->next->prev = tmp->prev;
            }
            if (tmp == tail) {
                tail = tmp->prev; 
            }
            delete tmp;
        }
    }
}
void DoublyLinkedList::PrintLinkedList(){
    Node *tmp = head;
    while(tmp != NULL){
        cout<<tmp->value;
        if(tmp->next != NULL){
            cout<<"<->";
        }
    tmp = tmp->next;
    }
    cout<<"<->NULL";
}

int main() {
    DoublyLinkedList d;
    cout<<"\nInserting Node at Beginning\n";
    d.InsertNodeAtFront(0);
    d.PrintLinkedList();
    cout<<"\nInserting Node at End\n";
    d.InsertNodeAtEnd(3);
    d.PrintLinkedList();
    cout<<"\nInserting Before a Value\n";
    d.InsertNodeBeforeGivenVal(1,3);
    d.PrintLinkedList();
    cout<<"\nInserting After a Value\n";
    d.InsertNodeAfterGivenVal(2,1);
    d.PrintLinkedList();
    cout<<"\nDeleting head node\n";
    d.DelHeadNode();
    d.PrintLinkedList();
    cout<<"\nDeleting tail node\n";
    d.DelTailNode();
    d.PrintLinkedList();
    cout<<"\nDeleting particular node\n";
    d.DelParticularNode(2);
    d.PrintLinkedList();
    return 0;
}
