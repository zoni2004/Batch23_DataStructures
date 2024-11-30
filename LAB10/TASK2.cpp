#include <iostream>
using namespace std;

void heapifyUp(int heap[], int i) {
    int parent = (i - 1) / 2;
    if (i > 0 && heap[i] < heap[parent]) {
        swap(heap[i], heap[parent]);
        heapifyUp(heap, parent);
    }
}

void insert(int heap[], int &n, int value) {
    heap[n] = value;
    n++;
    heapifyUp(heap, n - 1);
}

void heapifyDown(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(heap, n, smallest);
    }
}

void deleteRoot(int heap[], int &n) {
    heap[0] = heap[n - 1];
    n--;
    heapifyDown(heap, n, 0);
}

int* findKLargest(int heap[], int n, int k, int arr[], int size) {
    int heapSize = 0;

    for (int i = 0; i < k; i++) {
        insert(heap, heapSize, arr[i]);
    }

    for (int i = k; i < size; i++) {
        if (arr[i] > heap[0]) {  
            deleteRoot(heap, heapSize);  
            insert(heap, heapSize, arr[i]);  
        }
    }

    return heap;
}

int main() {
    int arr[] = {10, 4, 5, 8, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int heap[k]; 

    int* max = findKLargest(heap, 0, k, arr, size); 

    cout << "The " << k << " largest elements are: ";
    for (int i = 0; i < k; i++) {
        cout << max[i] << " ";
    }

    return 0;
}
