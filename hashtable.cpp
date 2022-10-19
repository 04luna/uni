// Hash Table with Separate chaining
#include<iostream>
using namespace std;

struct item{
	string name;
	string drink;
	item* next;
};

class HashManager{
	static const int size = 10;
	item* HashTable[size];

public:
	HashManager(){
		for(int i=0;i<size;++i){
			HashTable[i] = new item;
			HashTable[i]->name = "empty";
			HashTable[i]->drink = "empty";
			HashTable[i]->next = NULL;
		}
	}

	int hash(string name){
		int sum = 0;
		for(int i=0;i<name.length();++i){
			sum+=(int)name[i];
		}
		return sum%this->size;
	}
	
	void addItem(string name,string drink){
		int index = hash(name);

		if(HashTable[index]->name == "empty"){
			HashTable[index]->name = name;
			HashTable[index]->drink = drink;
		}
		else{
			item* newitem = new item;
			newitem->name = name;
			newitem->drink = drink;
			newitem->next = HashTable[index];
			HashTable[index] = newitem;
		}
	}


	int itemsInIndex(int index){
		int count = 0;
		item* temp = HashTable[index];
		if(temp->name == "empty") return count;
		else{
			++count;
			while(temp->next != NULL){
				++count;
				temp = temp->next;
			}
			return count;
		}
	}

	void printItemsInIndex(int i){
		int number = itemsInIndex(i);
		if(number <= 1)
			cout<<"Index "<<i<<"("<<number<<")"<<": "<<HashTable[i]->name<<" => "<<HashTable[i]->drink<<endl;
		else{
			cout<<"Index "<<i<<"("<<number<<")"<<": ";
			item* temp = HashTable[i];
			while(temp->next != NULL){
				cout<<temp->name<<" => "<<temp->drink<<" -> ";
				temp = temp->next;
			}
			cout<<temp->name<<" => "<<temp->drink<<endl;
		}
	}

	void printTable(){
		cout<<"----- Hash Table Contents -----"<<endl;
		for(int i=0;i<size;++i){
			printItemsInIndex(i);
		}
		cout<<"-------------------------------"<<endl<<endl;
	}

	void findDrink(string name){
		int index = hash(name);
		if(itemsInIndex(index) == 0){
			cout<<name<<" does not exist in the dictionary..."<<endl;
		}
		else{
			bool found = false;
			item* temp = HashTable[index];
			while(temp != NULL){
				if(temp->name == name){
					cout<<"Favouite drink of "<<temp->name<<" is : "<<temp->drink<<endl;
					found = true;
					break;
				}
				temp = temp->next;
			}
			if(found == false)
				cout<<name<<" does not exist in the dictionary..."<<endl;
		}
	}

	void removeItem(string name){
		int index = hash(name);
		item* delptr;
		item* current;
		item* previous;
	
		if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
			cout<<name<<" does not exist in the dictionary..."<<endl;
		else if(HashTable[index]->name == name && HashTable[index]->next == NULL){
			HashTable[index]->name = "empty";
			HashTable[index]->drink = "empty";
			cout<<name<<" was removed from the dictionary..."<<endl;
		}
		else if(HashTable[index]->name == name){
			delptr = HashTable[index];
			HashTable[index] = HashTable[index]->next;
			delete delptr;
			cout<<name<<" was removed from the dictionary..."<<endl;
		}
		else{
	            	current = HashTable[index]->next;
	                previous = HashTable[index];
	                while(current != NULL && current->name != name){
	                    previous = current;
	                    current = current->next;
	                }
	                if(current == NULL)
	                    cout<<name<<" does not exist in the dictionary..."<<endl;
	                else{
	                    delptr = current;
	                    previous->next = current->next;
	                    delete delptr;
	                    cout<<name<<" was removed from the dictionary..."<<endl;
	                }
		}
	}
};

int main(){
	HashManager* dictionary = new HashManager();
	cout<<"SuriyaAtthai hash: "<<dictionary->hash("SuriyaAtthai")<<endl;
	cout<<"Sailu hash: "<<dictionary->hash("Sailu")<<endl;

	dictionary->addItem("Raj Abishek","Coke");
	dictionary->addItem("Sailu","Pepsi");
	dictionary->addItem("Pragi","7up");
	dictionary->addItem("Dhana","LoveO");
	dictionary->addItem("Kaniamuthu","Maaza");
	dictionary->addItem("Aadithya","ThumbsUp");
	dictionary->addItem("Prasath","Miranda");
	dictionary->addItem("Birla Devi","Sprite");
	dictionary->addItem("Vijayragavan","Bovonto");
	dictionary->addItem("SuriyaAtthai","Sprite");


	dictionary->printTable();
	dictionary->findDrink("Sailu");
	dictionary->removeItem("Sailu");
	dictionary->printTable();
	dictionary->findDrink("Sailu");
	delete dictionary;
	return 0;
}