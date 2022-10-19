// Linked List
#include<iostream>
using namespace std;

template <class datatype>
class Linkedlist{
	Linkedlist* head;
public:
	datatype data;
	Linkedlist* next;
	Linkedlist(){
		head = NULL;
		next = NULL;
	}

	void insertAtBeginning(datatype data){
		Linkedlist<datatype>* newNode = new Linkedlist<datatype>();
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}

	void deleteAtBeginning(){
		Linkedlist* temp = head;
		head = head->next;
		delete temp;
	}

	void insertAtPosition(datatype data, int position){
		Linkedlist<datatype>* newNode = new Linkedlist<datatype>();
		newNode->data = data;
		Linkedlist* temp = head;
		for(int i=0;i<position - 2;++i){
			temp = temp->next;
		}
		//temp hold the address of the node before the position
		newNode->next = temp->next;
		temp->next = newNode;
	}

	void deleteAtPosition(int position){
		Linkedlist* temp = head;
		for(int i=0;i<position - 2;++i){
			temp = temp->next;
		}
		//temp hold the address of the node before the position
		Linkedlist* positionNode = temp->next;
		temp->next = positionNode->next;
		delete positionNode;
	}

	void insertAtEnd(datatype data){
		Linkedlist* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		Linkedlist<datatype>* newNode = new Linkedlist<datatype>();
		newNode->data = data;
		newNode->next = NULL;
		temp->next = newNode;
	}

	void deleteAtEnd(){
		Linkedlist* temp = head;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
	}

	bool isEmpty(){
		if(head == NULL)
			return true;
		return false;
	}

	void search(int element){
		Linkedlist* temp = head;
		int position = 0;
		while(temp != NULL){
			++position;
			if(temp->data == element){
				cout<<"Element "<<element<<" found at position "<<position<<endl;
				return;
			}
			temp = temp->next;
		}
		cout<<"The element "<<element<<" is not present in the list"<<endl;
	}

	void reverse(){
		Linkedlist* current = head;
		Linkedlist* prev = NULL;
		Linkedlist* nextNode;
		while(current != NULL){
			nextNode = current->next;
			current->next = prev;
			prev = current;
			current = nextNode;
		}
		head = prev;
	}

	void display(){
		Linkedlist* temp = head;
		while(temp != NULL){
			if(temp->next != NULL)
				cout<<temp->data<<" | ";
			else
				cout<<temp->data<<endl;
			temp = temp->next;
		}

	}
};

int main(){
	Linkedlist<int>* list = new Linkedlist<int>();
	list->insertAtBeginning(2);
	list->insertAtBeginning(4);
	list->insertAtBeginning(5);
	list->insertAtBeginning(3);
	list->insertAtBeginning(1);
	list->insertAtBeginning(6);
	list->display();
	cout<<"Insert 9 at position 3: "; list->insertAtPosition(9,3);
	list->display();
	cout<<"Insert 9 from position 3: "; list->deleteAtPosition(3);
	list->display();
	cout<<"Insert 11 at end: "; list->insertAtEnd(11);
	list->display();
	cout<<"Delete from end: "; list->deleteAtEnd();
	list->display();
	list->search(5);
	list->reverse();
	list->display();
	return 0;
}