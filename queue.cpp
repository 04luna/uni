// Queue
#include<iostream>
using namespace std;

template <class datatype>
class QueueInterface{
public:
	virtual void enqueue(datatype data) = 0;
	virtual void dequeue() = 0;
	virtual bool isEmpty() = 0;
	virtual bool isFull(){
		return true;
	};
	virtual void display() = 0;
	virtual datatype getFront() = 0;
};

template <class datatype>
class QueueAsArray:public QueueInterface<datatype>{
	int front;
	int rear;
	int size;
	datatype* array;
public:
	QueueAsArray(int size){
		front = rear = -1;
		this->size = size;
		array = new datatype[size];
	}

	void enqueue(datatype data){
		if(isEmpty()){
			front = 0;
		}

		if(!isFull()){
			++rear;
			array[rear] = data;
		}
		else
			cout<<"The array is full, cannot add "<<data<<endl;
	}

	datatype getFront(){
		if(!isEmpty())
			return array[front];
		else
			cout<<"The queue is empty..."<<endl;
		return -1;
	}

	void dequeue(){
		++front;
		if(front > rear)
			rear = front = -1;
	}

	void display(){
		if(!isEmpty()){
			for(int i=front;i<=rear;++i){
				if(i!=rear)
					cout<<array[i]<<" | ";
				else
					cout<<array[i]<<endl;
			}
		}
		else
			cout<<"The queue is empty..."<<endl;
	}

	bool isFull(){
		if(rear == size - 1)
			return true;
		return false;
	}

	bool isEmpty(){
		if(rear == -1 && front == -1)
			return true;
		return false;
	}

};

template <class datatype>
class QueueAsLinkedlist:public QueueInterface<datatype>{
	datatype data;
	QueueAsLinkedlist* head;
	QueueAsLinkedlist* tail;
	QueueAsLinkedlist* next;
public:
	QueueAsLinkedlist(){
		head = NULL;
	}

	void enqueue(datatype data){
		QueueAsLinkedlist<datatype>* newNode = new QueueAsLinkedlist<datatype>();
		newNode->data = data;
		newNode->next = NULL;
		if(isEmpty()){	
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = newNode;
		}
	}

	datatype getFront(){
		if(!isEmpty()){
			return head->data;
		}
		else
			cout<<"The queue is empty..."<<endl;
		return -1;
	}

	void dequeue(){
		if(!isEmpty()){
			QueueAsLinkedlist* temp = head;
			head = head->next;
			delete temp;
		}
		else
			cout<<"The queue is empty..."<<endl;
	}

	void display(){
		if(!isEmpty()){
			QueueAsLinkedlist* temp = head;
			while(temp != NULL){
				if(temp->next != NULL)
					cout<<temp->data<<" | ";
				else
					cout<<temp->data<<endl;
				temp = temp->next;
			}
		}
		else
			cout<<"The queue is empty..."<<endl;
	}

	bool isEmpty(){
		if(head == NULL)
			return true;
		return false;
	}

};

template <class datatype>
class QueueFacade{
public:
	static QueueInterface<datatype>* getInstance(string type = "linkedlist",int size = 4){
		if(type == "array")
			return new QueueAsArray<datatype>(size);
		else
			return new QueueAsLinkedlist<datatype>();
	}
};

int main(){
	QueueInterface<int>* queue = QueueFacade<int>::getInstance();
	cout<<"Enqueing 3..."<<endl;queue->enqueue(3);
	cout<<"Enqueing 1..."<<endl;queue->enqueue(1);
	cout<<"Enqueing 2..."<<endl;queue->enqueue(2);
	cout<<"Contents: "<<endl;queue->display();
	cout<<"Enqueing 5..."<<endl;queue->enqueue(5);
	cout<<"Contents: "<<endl;queue->display();
	cout<<"Enqueing 9..."<<endl;queue->enqueue(9);
	cout<<"Contents: "<<endl;queue->display();
	cout<<"Dequeing..."<<endl;queue->dequeue();
	cout<<"Contents: "<<endl;queue->display();
	cout<<"Dequeing..."<<endl;queue->dequeue();
	cout<<"Dequeing..."<<endl;queue->dequeue();
	cout<<"Contents: "<<endl;queue->display();
	cout<<"Dequeing..."<<endl;queue->dequeue();
	cout<<"Contents: "<<endl;queue->display();
	cout<<"Dequeing..."<<endl;queue->dequeue();
	cout<<"Contents: "<<endl;queue->display();
	return 0;
}