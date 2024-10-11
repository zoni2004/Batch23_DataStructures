#include <iostream>
using namespace std;

class Node {
    int value;
    Node *next;
    Node *prev;

public:
    Node(int value) : next(nullptr), prev(nullptr) {
        this->value = value;
    }

    friend class DoublyLinkedList;
};

class DoublyLinkedList {
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int value) {
        Node *n = new Node(value);
        if (head == nullptr) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void print() {
        Node *tmp = head;
        cout<<"NULL<-";
        while (tmp != nullptr) {
            cout <<tmp->value << "<=>";
            tmp = tmp->next;
        }
        cout << "->NULL";
    }

    void swap(Node *a, Node *b) {
        if (a == b) return;

        int temp = a->value;
        a->value = b->value;
        b->value = temp;
    }

    Node* partition(Node* start, Node* end) {
        int pivot = end->value;
        Node* pIndex = start;

        for (Node* curr = start; curr != end; curr = curr->next) {
            if (curr->value < pivot) {
                swap(pIndex, curr);
                pIndex = pIndex->next;
            }
        }
        swap(pIndex, end);
        return pIndex;
    }

    void quickSort(Node* start, Node* end) {
        if (start != end) {
            Node* pivotIndex = partition(start, end);

            if (pivotIndex != start) {
                Node* temp = start;
                while (temp != nullptr && temp->next != pivotIndex) {
                    temp = temp->next;
                }
                quickSort(start, temp); 
            }
            quickSort(pivotIndex->next, end); 
        }
    }

    void sort() {
        if (head != nullptr) { 
            quickSort(head, tail);
        }
    }
};

int main() {
    DoublyLinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(7);
    ll.insertAtEnd(8);
    ll.insertAtEnd(9);
    ll.insertAtEnd(1);
    ll.insertAtEnd(5);
    ll.insertAtEnd(3);

    std::cout << "\nOriginal list: ";
    ll.print();

    ll.sort();

    std::cout << "\nSorted list: ";
    ll.print();
    return 0;
}
