/*Merge K Sorted Lists using a Min-Heap. Given K sorted linked lists, write a function to merge them into a single sorted list.*/
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int value){
        data = value;
        next = NULL;
    }
    friend class PriorityQueue;
};

class PriorityQueue{
    Node ** heap;
    int capacity;
    int size;

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && heap[i]->data < heap[parent]->data) {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left]->data < heap[smallest]->data) {
            smallest = left;
        }

        if (right < size && heap[right]->data < heap[smallest]->data) {
            smallest = right;
        }

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    public:
    PriorityQueue(int cap){
        capacity = cap;
        size = 0;
        heap = new Node*[capacity]; 
    } 

    void insert(Node* n) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        heap[size] = n;
        size++;
        heapifyUp(size - 1);
    }

    Node* extractMin() {
        if (size == 0) {
            return nullptr;
        }

        Node* minNode = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return minNode;
    }

    bool isEmpty() {
        return size == 0;
    }
    
    ~PriorityQueue() {
        delete[] heap;
    }
};

Node* mergeKLists(Node* lists[], int k) {
        PriorityQueue pq(k); 
        
        for (int i = 0; i < k; i++) {
            if (lists[i]) {
                pq.insert(lists[i]);
            }
        }
        Node* dummy = new Node(0);  
        Node* tail = dummy;
        
        while (!pq.isEmpty()) {
            Node* minNode = pq.extractMin();
            tail->next = minNode;  
            tail = tail->next;   
            
            if (minNode->next) {
                pq.insert(minNode->next);
            }
        }

    return dummy->next; 
    }
    
    void printList(Node* head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
    cout << endl;
    }

int main(){
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* list3 = new Node(2);
    list3->next = new Node(6);

    Node* lists[] = {list1, list2, list3};

    Node* mergedList = mergeKLists(lists, 3);

    printList(mergedList);

    return 0;
}
