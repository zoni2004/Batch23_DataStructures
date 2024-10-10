#include<iostream>
using namespace std;

class Queue{
	int *arr;
	int capacity;
	int front;
	int rear;
	
	public:
		Queue(int size){
			capacity = size;
			arr = new int[capacity];
			front = 0;
			rear = -1;
		}
		
		~Queue(){
			delete [] arr;
		}
		
		bool isFull(){
			if(rear == capacity-1){
				cout<<"Overflow";
				return true;
			}
		return false;
		}
		
		bool isEmpty(){
			if(front > rear){
				cout<<"Underflow";
				return true;
			}		
		return false;
		}
		void enqueue(int value){
			if(!isFull()){
				arr[++rear] = value;
			}
		}
		
		int dequeue(){
			if(!isEmpty()){
				return arr[front++];
			}
		}
		
		int Front(){
			if(!isEmpty()){
				return arr[front];
			}
		}
		
		void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << "|";
        }
        cout << endl;
    }
		
};  

int main(){
	Queue q(10);
	
	for(int i=1; i<11; i++){
		q.enqueue(i);
	}
	q.print();
	
	cout<<"\nRemoving 5 people";
	for(int i=0; i<5; i++){
		q.dequeue();
		cout<<"\n";
		q.print();
	}
	
	cout<<"\nAttempting to add 5 people\n";
	for(int i=11; i<15; i++){
		 q.enqueue(i);
         q.print(); //gives overflow as the front and rear pointers have not been changed
	}
//this issue can be handled by implememnting a circular queue instead of a linear queue
} 
