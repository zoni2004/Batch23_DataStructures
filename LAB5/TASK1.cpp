#include <iostream>
using namespace std;

//sorting in ascending order using bubble sort
void sortArr(int arr[], int size){
        if(size == 1){
            return;
        }
        for(int i=0; i<size-1; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
    sortArr(arr, size-1);
}

int main() {
    int arr[] = {2,9,8,3,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"\nUnsorted array is:\n";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    sortArr(arr, size);
    cout<<"\nSorted array is:\n";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<"\t";
    }
    
    return 0;
}
