#include<iostream>
using namespace std;

int main(){
	//using dynamic allocation to declare the array rows
	int** jaggedArr = new int*[5];
	//making an array to store the size of each rows number of columns
	int size[5];
	//dynamially allocating the size of each column to the array using a for loop that takes the size array input
	for(int i=0; i<5; i++){
		cout<<"\nEnter the size of row "<<i+1;
		cin>>size[i];
		jaggedArr[i] = new int [size[i]]; //allocating column size
	}
	
	//populating the jagged array
	for(int i = 0; i<5; i++){
		for(int j=0; j<size[i]; j++){
			cout<<"\nEnter element of row "<<i+1<<" and column "<<j+1<<"\n";
			cin>>*(*(jaggedArr+i)+j);
		}
	}
	
	//printing the input arrays
	cout<<"\nBefore changes to the array";
	cout<<"{";
	for(int i=0; i<5; i++){
		for(int j=0; j<size[i]; j++){
			cout<<*(*(jaggedArr+i)+j)<<"\t";
		}
	cout<<"\n";
	}
	cout<<"}";
	
	//declaring the new size 
	int newSize = 10;
	int** newArray = new int*[5];
	//allocating memory for the new array
	for(int i=0; i<5; i++){
		newArray[i] = new int[10];
		
		//copying existing elements
	    for (int j=0; j<size[i]; j++){
	    	 newArray[i][j] = jaggedArr[i][j];
		}
		
		//adding new elements
      	for(int j = size[i]; j<10; j++){
      		cout<<"\nEnter new element for row "<<i+1<<" and column "<<j+1<<"\n";
      		cin>>*(*(newArray+i)+j);
		}
		
		//deallocating old row
		delete[] jaggedArr[i];
	}
	
	// Update jaggedArr to point to the new arrays
    delete[] jaggedArr;
    jaggedArr = newArray;
    
	//printing the input arrays
	cout<<"\nAfter changes to the array";
	cout<<"{";
	for(int i=0; i<5; i++){
		for(int j=0; j<10; j++){
			cout<<*(*(jaggedArr+i)+j)<<"\t";
		}
	cout<<"\n";
	}
	cout<<"}";

	//deallocating memory to make columns of size 10
	for(int i=0; i<5; i++){
		delete[] jaggedArr[i];
		delete[] jaggedArr;
	}

return 0;
}
TASK1.cpp
Displaying TASK1.cpp.
Q1 Q2 Submission
Ms Alishba Subhani
•
Aug 26
10 points
Due Aug 26, 11:00 AM
Class comments
