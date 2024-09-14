
#include<iostream>
using namespace std;

void bubbleSort(int arr[], int size){
	int tmp;
	bool swapped;
	for(int i=0; i<size; i++){
		swapped = false;
		for(int j =0; j<(size-1-i); j++){
			if(arr[j+1]<arr[j]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				swapped = true;
			}
		}
		if (!swapped) {
            break;
        }
	}
}

void SelectionSort(int arr[], int size){
	int tmp;
	for(int i=0; i<size-1; i++){
		int minIndex = i;
		for(int j=i+1; j<size; j++){
			if(arr[minIndex] > arr[j]){
				minIndex = j;
			}
		}
		if(minIndex!=i){
			tmp = arr[minIndex];
			arr[minIndex] = arr[i];
			arr[i] = tmp;
		}
	}
}

void InsertionSort(int arr[], int size){
	for(int i=1; i<size-1; i++){
		int key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
	arr[j+1] = key;
	}
}

void ShellSort(int arr[], int size){
	for(int gap = size/2; gap>0; gap/=2){
		for(int i=gap;i<size;i++){
			int key = arr[i];
			int j;
			for(j=i; j>=gap && arr[j-gap]>key; j-=gap){
				arr[j] = arr[j-gap];
			}
			arr[j] = key;
		}
	}
}

void CombSort(int arr[], int size){
	int gap = size;
	const double shrink = 0.769;
	bool sorted = false;
	for(gap=gap*shrink; gap>0; gap*=shrink){
		if(gap<1){
			gap = 1;
			sorted = true;
	    }
	    for (int i = 0; i + gap < size; i++) {
            if (arr[i + gap] < arr[i]) {
                // Swap elements
                int tmp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = tmp;
                
                sorted = false; 
            }
		}
	}
}

int LinearSearch(int arr[], int size, int target){
    for(int i=0; i<size; i++){
         if(arr[i] == target){
             return i;
         }
    }
    return -1;
}

int BinarySearch(int arr[], int size, int target){
	bool sorted = true;
	if(sorted == false){
		bubbleSort(arr,size);
		sorted = true;
	}
	else{
		bool isFound = false;
		int low = 0;
		int high = size-1;
		while(low <= high){
			int mid = (low+high)/2;
			if(arr[mid] == target){
			     return mid;
		    }
		    else if (arr[mid] < target) {
                 low = mid + 1; 
            }
            else if(arr[mid] > target){
                 high = mid - 1; 
            }   
        }
	}

    return -1;
}

int InterpolationSearch(int arr[], int size, int target){
    bool sorted = true;
    if(sorted == false){
        bubbleSort(arr,size);
        sorted = true;
    }
    else{
        bool isFound = false;
        int low = 0;
        int high = size-1;
        while(low <= high && target>=arr[low] && target <= arr[high]){
            if(low == high){
                if(arr[low] == target){
                    return low;
                }
            return -1;
            }
            int pos = (low + (((target-arr[low])*(high-low))/(arr[high]-arr[low])));
            if(arr[pos] == target){
                return pos;
            }
            if (arr[pos] < target) {
                 low = pos + 1;
            }
            else if(arr[pos] > target){
                 high = pos - 1;
            }  
    }
}

    return -1;
}


void printArr(int arr[], int size){
	cout<<"{";
	for(int i=0; i<size; i++){
		cout<<arr[i]<<",";
	}
	cout<<"}";
}

int main(){
	int arr[6] = {12,3,4,13,14,5};
	cout<<"\nUnsorted Array\n";
	printArr(arr,6);
	bubbleSort(arr,6);
	cout<<"\nSorting by Bubble Sort\n";
	printArr(arr,6);
	SelectionSort(arr,6);
	cout<<"\nSorting by Selection Sort\n";
	printArr(arr,6);
	InsertionSort(arr,6);
	cout<<"\nSorting by Insertion Sort\n";
	printArr(arr,6);
	ShellSort(arr,6);
	cout<<"\nSorting by Shell Sort\n";
	printArr(arr,6);
	CombSort(arr,6);
	cout<<"\nSorting by Comb Sort\n";
	printArr(arr,6);
	cout<<"\nLinear Search\n";
	int x = LinearSearch(arr,6,13);
	if(x == -1){
		cout<<"\nTarget not found";
	}
	else{
		cout<<"\nThe index is: \n"<<x;
	}
	cout<<"\nBinary Search\n";
	int y = BinarySearch(arr,6,13);
	if(y == -1){
		cout<<"\nTarget not found";
	}
	else{
		cout<<"\nThe index is: \n"<<y;
	}
	cout<<"\nInterlopation Search\n";
	int z = InterpolationSearch(arr,6,13);
	if(z == -1){
		cout<<"\nTarget not found";
	}
	else{
		cout<<"\nThe index is: \n"<<z;
	}
}
