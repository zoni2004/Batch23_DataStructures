/*Sliding Window Maximum. Given an array nums and an integer k, implement a function that finds the maximum 
element in every sliding window of size k using a max-heap.*/

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left]>arr[largest]){
        largest = left;
    }

    if(right < n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n){
    for(int i=(n/2)-1; i>=0; i--){
        heapify(arr, n, i);
    }
}

int peek(int arr[]){
    return arr[0];
}

int* findMax(int arr[], int n, int k, int MaxArr[]) {
    int window[k];
    
    int totalWindows = n - k + 1; 
    for (int i = 0; i < totalWindows; i++) {
        for (int j = 0; j < k; j++) {
            window[j] = arr[i + j];
        }
        buildMaxHeap(window, k);
        MaxArr[i] = peek(window);  
    }

    return MaxArr;
}

int printHeap(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<"\n"<<arr[i];
    }
}

int main(){
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    
    int maxArr[size - k + 1]; 
    findMax(arr, size, k, maxArr);  
    for (int i = 0; i < size - k + 1; i++) {
        cout << maxArr[i] << " ";
    }

    return 0;
}
