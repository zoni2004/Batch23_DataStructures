#include <iostream>
using namespace std;

int binarySearch(int arr[],int x,int low ,int high){
    if(high>=low){
        int mid =  low+((high-low)/2);
        if(arr[mid] == x){
            return arr[mid];
        }
        else if(arr[mid]>x){
            return binarySearch(arr, x, low, mid-1);
        }
        else if(arr[mid]<x){
            return binarySearch(arr, x, mid+1, high);
        }
    }
return -1;
}

int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
    int x;
    cout<<"\nEnter the element you want to find in the array";
    cin>>x;
    int result = binarySearch(arr, x, 0, n-1);
    if (result == -1){
        cout << "Element is not present in array";
    }
    else{
       cout << "Element is present at index " << result; 
    } 
    return 0;
}
