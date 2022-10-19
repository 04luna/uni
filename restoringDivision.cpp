// Restoring Division
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

class LinkedlistManager{
    public:
    int data;
    LinkedlistManager* next;
    LinkedlistManager* previous;
    LinkedlistManager* head;
    LinkedlistManager* tail;

        LinkedlistManager(){head = NULL;}
        LinkedlistManager(int data){
            this->data = data;
            head = NULL;
            this->next = NULL;
            this->previous = NULL;
        }

        void addNodeAtBeginning(int data){
            LinkedlistManager* newNode = new LinkedlistManager(data);
            newNode->next = head;
            newNode->previous = NULL;
            if(head != NULL){
            	head->previous = newNode;
            }else{
            	tail = newNode;
            }
            head = newNode;
        }

        LinkedlistManager* getHead(){
            return head;
        }

        LinkedlistManager* getTail(){
            return tail;
        }

        void addNodeAtEnd(){
        
        }

        void printDetails(){
            LinkedlistManager* temp = head;
            if(head == NULL){
                    cout<<"The linked list is empty !"<<endl;
                    return;
                }
            while(temp!=NULL){
                cout<<temp->data<<" | ";
                temp = temp->next;
            }
            cout<<endl;
        }

        int mostSignificantBit(){
        	return head->data;
        }

        void setLeastSignificantBit(int data){
        	tail->data = data;
        }

        LinkedlistManager* createCopy(){
        	LinkedlistManager* temp = tail;
        	LinkedlistManager* newManager = new LinkedlistManager();
        	while(temp != NULL){
        		newManager->addNodeAtBeginning(temp->data);
        		temp = temp->previous;
        	}
        	return newManager;
        }
};

class Converter{
    int data;
    int n;
    LinkedlistManager* manager;
    public:
        Converter(LinkedlistManager* manager,int data,int n){
            this->manager = manager;
            this->data = data;
            this->n = n;
        }

        Converter(LinkedlistManager* manager,int n){
            this->manager = manager;
            this->n = n;
        }

        Converter(LinkedlistManager* manager){
            this->manager = manager;
        }

        LinkedlistManager* convertToBinary(){
            int count = 0;
            while(data){
                ++count;
                manager->addNodeAtBeginning(data%2);
                data = data/2;
            }
            if(count<n){
                for(int i=count;i<n;++i){
                    manager->addNodeAtBeginning(0);
                }
            }
            return manager;
        }

        LinkedlistManager* convertToTwosComplement(){
            LinkedlistManager* temp = manager->getTail();
            bool firstOneFound = false;
            while(temp != NULL){
            	if(temp->data == 0){
            		if(firstOneFound)
            			temp->data = 1;
            	}
            	else{
            		if(!firstOneFound)
            			firstOneFound = true;
            		else{
            			temp->data = 0;
            		}
            	}
            	temp = temp->previous;
            }

            return manager;
        }

        LinkedlistManager* prepareForAcummalator(){
            for(int i=0;i<n;++i){
                manager->addNodeAtBeginning(0);
            }
            return manager;
        }
};

class RestoringDivision{
    public:
    int getBinarySize(int divident,int divisor){
        for(int i=1;i<20;++i){
            if(divident <= pow(2,i)-1 && divident >= -1*pow(2,i) && divisor <= pow(2,i)-1 && divisor >= -1*pow(2,i))
                return i;
        }
    }

    void leftshift(LinkedlistManager* operand1,LinkedlistManager* operand2){
        LinkedlistManager* temp1 = operand1->getHead();
        LinkedlistManager* temp2 = operand2->getHead();

        while(temp1->next != NULL){
        	temp1->data = temp1->next->data;
        	temp1 = temp1->next;
        }
        temp1->data = temp2->data;

        while(temp2->next != NULL){
        	temp2->data = temp2->next->data;
        	temp2 = temp2->next;
        }
    }

    void add(LinkedlistManager* operand1,LinkedlistManager* operand2){
    	LinkedlistManager* temp1 = operand1->getTail();
        LinkedlistManager* temp2 = operand2->getTail();
        int carry = 0;
        while(temp1 != NULL){
        	int data1 = temp1->data;
        	int data2 = temp2->data;
        	if(data1 == 0 && data2 == 0){
        		if(carry == 0){
        			temp1->data = 0;
        			carry = 0;
        		}else{
        			temp1->data = 1;
        			carry = 0;
        		}
        	}
        	else if(data1 == 0 && data2 == 1){

        		if(carry == 0){
        			temp1->data = 1;
        		}else{
        			temp1->data = 0;
        			carry = 1;
        		}
        	}
        	else if(data1 == 1 && data2 == 0){
        		if(carry == 0){
        			temp1->data = 1;
        		}else{
        			temp1->data = 0;
        			carry = 1;
        		}
        	}else{
        		if(carry == 0){
        			temp1->data = 0;
        			carry = 1;
        		}else{
        			temp1->data = 1;
        			carry = 1;
        		}
        	}

        	temp1 = temp1->previous;
        	temp2 = temp2->previous;
        }
        
    }

    void subract(LinkedlistManager* operand1,LinkedlistManager* operand2){
    	LinkedlistManager* temp1 = operand1->getHead();
        LinkedlistManager* temp2 = operand2->getHead();
        LinkedlistManager* twosComplement =  operand2->createCopy();
        Converter* converter = new Converter(twosComplement);
        twosComplement = converter->convertToTwosComplement();
        add(operand1,twosComplement);
        delete converter;
        delete twosComplement;

    }
};

int main(){
    RestoringDivision* divider = new RestoringDivision();
    int divident,divisor;
    cout<<"Enter the divident: ";
    cin>>divident;
    cout<<"Enter the divisor: ";
    cin>>divisor;
    
    int n = divider->getBinarySize(divident,divisor);
    cout<<"The number of required bits is: "<<n<<endl;
    
    LinkedlistManager* dividentManager = new LinkedlistManager();
    Converter* converter = new Converter(dividentManager,divident,n);
    dividentManager = converter->convertToBinary();
    delete converter;
    cout<<"Divident: "; dividentManager->printDetails();
    
    LinkedlistManager* divisorManager = new LinkedlistManager();
    converter = new Converter(divisorManager,divisor,n);
    divisorManager = converter->convertToBinary();
    delete converter;
    cout<<"Divisor: "; divisorManager->printDetails();

    LinkedlistManager* acummalatorManager = new LinkedlistManager();
    converter = new Converter(acummalatorManager,n);
    acummalatorManager = converter->prepareForAcummalator();
    delete converter;
    cout<<"Accumalator: "; acummalatorManager->printDetails();

    // cout<<"After left shift: "<<endl;
    // divider->leftshift(acummalatorManager,dividentManager);
    // acummalatorManager->printDetails();
    // dividentManager->printDetails();
    // delete divider;

    // cout<<"After addition: "<<endl;
    // divider->add(acummalatorManager,divisorManager);
    // acummalatorManager->printDetails();
    // divisorManager->printDetails();
    // delete divider;

    // cout<<"After addition: "<<endl;
    // divider->subract(acummalatorManager,divisorManager);
    // acummalatorManager->printDetails();
    // divisorManager->printDetails();
    // delete divider;
    cout<<endl;
    n = n+1;
    while(--n){
    	cout<<"Count "<<n<<endl;
    	divider->leftshift(acummalatorManager,dividentManager);
    	cout<<"After leftshift: "<<endl;
    	cout<<"Accumalator: "; acummalatorManager->printDetails();
    	cout<<"Divident: "; dividentManager->printDetails();
    	cout<<endl;

    	divider->subract(acummalatorManager,divisorManager);
    	cout<<"After A = A - M: "<<endl;
    	cout<<"Accumalator: "; acummalatorManager->printDetails();
    	cout<<"Divisor: "; divisorManager->printDetails();
    	cout<<endl;

    	if(acummalatorManager->mostSignificantBit() == 1){
    		cout<<"Most Significant bit of A is 1"<<endl;
    		dividentManager->setLeastSignificantBit(0);
    		cout<<"Setting Q0 to 0"<<endl;
    		cout<<"Divident: "; dividentManager->printDetails();
    		cout<<endl;
    		divider->add(acummalatorManager,divisorManager);
    		cout<<"After A = A + M: "<<endl;
    		cout<<"Accumalator: "; acummalatorManager->printDetails();
    		cout<<"Divisor: "; divisorManager->printDetails();
    		cout<<endl;

    	}else{
    		cout<<"Most Significant bit of A is 0"<<endl;
    		dividentManager->setLeastSignificantBit(1);
    		cout<<"Setting Q0 to 1"<<endl;
    		cout<<"Divident: "; dividentManager->printDetails();
    		cout<<endl;
    	}
    	cout<<"--------------------------------------------------------"<<endl;

    }
    cout<<"Remainder: "; acummalatorManager->printDetails();
    cout<<"Quotient: "; dividentManager->printDetails();
    return 0;
}