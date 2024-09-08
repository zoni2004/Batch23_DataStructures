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
    
    void InsertNodeAtEnd(const int data);
    void SortAscendingOrder();
    void RemovingDuplicates();
    void PrintLinkedList();
};

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

void DoublyLinkedList::SortAscendingOrder(){
    if(head == NULL){
        cout<<"\nThe list is empty\n";
        return;
    }
    else if(head == tail){
        PrintLinkedList();
        return;
    }
    else{
        Node *sorted = NULL;
        Node *ctrPtr = head;
        while(ctrPtr != NULL){
            Node *next = ctrPtr->next;
            if(sorted == NULL || sorted->value >= ctrPtr->value){
                ctrPtr->next = sorted;
                ctrPtr->prev = NULL;
                if(sorted != NULL){
                    sorted->prev = ctrPtr;
                }
                sorted = ctrPtr;
            }
            else{
               Node *tmp = sorted;
               while (tmp->next != NULL && tmp->next->value< ctrPtr->value) {
                   tmp = tmp->next;
               }
               ctrPtr->next = tmp->next;
               if (tmp->next != NULL) {
                tmp->next->prev = ctrPtr;
               }
               tmp->next = ctrPtr;
               ctrPtr->prev = tmp;
        }
            ctrPtr = next;
       }

        head = sorted;
        Node *tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tail = tmp;
    }
}

void DoublyLinkedList::RemovingDuplicates(){
     if (head == NULL) {
        cout << "\nThe list is empty\n";
        return;
    }

    Node *ctrPtr = head;
    while (ctrPtr != NULL) {
        Node *tmp = ctrPtr;
        while (tmp->next != NULL) {
            if (tmp->next->value == ctrPtr->value) {
                Node *toDel = tmp->next;
                tmp->next = tmp->next->next;
                if (tmp->next != NULL) {
                    tmp->next->prev = tmp;
                }
                if (toDel == tail) {
                    tail = tmp;
                }
                delete toDel;
            } 
            else {
                tmp = tmp->next;
            }
        }
        ctrPtr = ctrPtr->next;
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
   int x;
   cout<<"\nEnter the amount of nodes \n";
   cin>>x;
   for(int i=0; i<x; i++){
       int element;
       cout<<"Enter the value of node "<<i+1<<" \n";
       cin>>element;
       d.InsertNodeAtEnd(element);
   }
   d.PrintLinkedList();
   cout<<"\nSorting the list in ascending order\n";
   d.SortAscendingOrder();
   d.PrintLinkedList();
   cout<<"\nDeleting Duplicates\n";
   d.RemovingDuplicates();
   d.PrintLinkedList();

    return 0;
}
