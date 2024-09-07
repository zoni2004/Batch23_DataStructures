#include<iostream>
using namespace std;

class Node{
	//data part of the node
	int data;
	//pointer part of the node
	Node *next;
	
	public:
		//constructor to intiazlize node
		Node():data(0),next(NULL){}
		//constructor to assign data to node
		Node(const int d):data(d),next(NULL){}
		
		//making a friend class to create the singley linked list
		friend class SingleyLinkedList;
};

//creating singley linked list class
class SingleyLinkedList{
	//making pointer for head node using node class
	Node *head;
	public:
		//constructor to intiazlize head pointer
		SingleyLinkedList():head(NULL){}
		//constructor to assign next head pointer 
		SingleyLinkedList(Node* n):head(n){}
		//function to insert node at start
		void InsertNodeatFront(const int val);
		//function to insert node at the end
		void InsertNodeatEnd(const int val);
		//function to insert node after a value
		void InsertNodeAfterValue(const int val, const int location);
		//function to insert node before a value
		void InsertNodeBeforeValue(const int val, const int location);
		//deleting head node
		void DelHeadNode();
		//deleting last node
		void DelLastNode();
		//deleting partocular node
		void DelParticularNode(const int value);
		//couting number of nodes
		void CountNodes();
		//function to print the linked list
		void PrintList();
};

void SingleyLinkedList::InsertNodeatFront(const int val){
	Node *n = new Node(val);
	if(head == NULL){
		head = n;
	}
	else{
		n->next = head;
		head = n;
	}
}

void SingleyLinkedList::InsertNodeatEnd(const int val){
	Node *n = new Node(val);
	if(head == NULL){
		head = n;
	}
	else{
		Node* tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
	tmp->next = n;
	n->next = NULL;
	}
}

void SingleyLinkedList::InsertNodeAfterValue(const int val, const int location){
	if(head != NULL){
		Node *n = new Node(val);
		Node* tmp = head;
		while(tmp->data != location){
			tmp = tmp->next;
		}
		n->next = tmp->next;
		tmp->next = n;
	}
	else{
		cout<<"There is no node with given location";
	}
}

void SingleyLinkedList::InsertNodeBeforeValue(const int val, const int location){
	Node* n = new Node(val);
	Node* prev = NULL;
	if (head != NULL){
		Node * tmp = head;
		while(tmp->data != location){
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = n;
		n->next = tmp;
	}
	else{
		cout<<"There is no node with given location";
	}
}

void SingleyLinkedList::DelHeadNode(){
	if(head != NULL){
		Node *tmp = head;
		head = tmp->next;
		delete tmp;
		tmp = NULL;
	}
	else{
		cout<<"List is already empty";
	}
}

void SingleyLinkedList::DelLastNode(){
	if(head != NULL){
		Node *ctrPtr = head;
		while(ctrPtr->next->next != NULL){
			ctrPtr = ctrPtr->next;
		}
		Node* tmp = ctrPtr->next;
		ctrPtr->next = NULL;
		delete tmp;
		tmp = NULL;
	}
	else{
		cout<<"List is already empty";
	}
}

void SingleyLinkedList::DelParticularNode(const int value){
	if(head != NULL){
		Node *tmp = head;
		Node *prev = NULL;
		while(tmp->data != value){
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = tmp->next;
		delete tmp;
		tmp = NULL;
	}                                                                                                                                                                                                                                                                                                                 
	else{
		cout<<"List is already empty";
	}
}

void SingleyLinkedList::CountNodes(){
	if(head != NULL){
		int count = 1;
		Node* tmp = head;
		while(tmp->next != NULL){
			count++;
		}
	cout<<"\nThe number of nodes is: "<<count;
	}
	else{
		cout<<"List is already empty";
	}
}
void SingleyLinkedList::PrintList(){
    cout<<"\n";
	Node *ctrPtr = head;
	while(ctrPtr->next != NULL){
		cout<<ctrPtr->data<<"->";
		ctrPtr = ctrPtr->next;
	}
	cout<<ctrPtr->data;
	cout<<"-> NULL";
}

int main(){
	SingleyLinkedList s;
	s.InsertNodeatFront(21);
	cout<<"\nPrinting after inserting a node at the head";
	s.PrintList();
	s.CountNodes();
	s.InsertNodeatEnd(23);
	cout<<"\nPrinting after inserting a node at the end";
	s.PrintList();
	s.InsertNodeAfterValue(24, 23);
	cout<<"\nPrinting after inserting a node after a specific value";
	s.PrintList();
	s.InsertNodeBeforeValue(22, 23);
	cout<<"\nPrinting after inserting a node before a specific value";
	s.PrintList();
	s.DelHeadNode();
	cout<<"\nPrinting after deleting head";
	s.PrintList();
	s.DelLastNode();
	cout<<"\nPrinting after deleting tail";
	s.PrintList();
	s.DelParticularNode(23);
	cout<<"\nPrinting after deleting a particular node";
	s.PrintList();
	s.CountNodes();
	return 0;
}
TASK1.cpp
Displaying TASK1.cpp.
Lab 03 Tasks
Ms Alishba Subhani
•
Sep 2
100 points
Due Tomorrow
Class comments
