#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class shop {
public:
	int id;
	string name;
	int price;
};

class node {

public:
	
	shop s;
	node* next;
};



class linkedlist{
	
	
	node* head = NULL;
	node* tail = NULL;

	public:


	void insertatstart(int x, string y, int z ) {
		node* temp = new node; 
		temp->s.id = x ;
		temp->s.name = y ;
		temp->s.price = z ;
		temp->next = head;
		head = temp; 
	}

	void insertatend(int x, string y, int z) {
		node* temp = new node;
		temp->s.id = x;
		temp->s.name = y;
		temp->s.price = z;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
		}
		else {
			tail = head;
			while (tail->next != NULL) {
				tail = tail->next;
			}
			tail->next = temp;
			tail = temp;

		}

	}

	void deletehead() {
		if (head == NULL) {
			cout << "Link list is already ded. \n";
		}
		else {
			node * temp = head;
			head = head->next;
			delete temp;
		}
	}

	void deleteend() {
		if (head == NULL) {
			cout << "Link list is already ded";
		}
		else if (head->next == NULL) {
			head = NULL;
		}
		else {
			node * temp = head;
			while (temp->next != NULL) {
				tail = temp;
				temp = temp->next;
			}
			tail->next = NULL;
			delete temp;
		}
	}

	void arrangeaccending() {
		node* temp = head->next;
		while (head->s.name < temp->s.name){
			temp = temp->next;

		}
			
	}


	void print() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->s.id << " ";
			cout << temp->s.name << " ";
			cout << temp->s.price << " ";
			cout << "\n";
			temp = temp->next;
		}
	}
};








//
//deletestart(){
//	if (head!=NULL){
//	node*temp=head;
//	head->next=head;
//	delete head;	
//	}
//	
//	
//}








int main() {

	linkedlist list;
	/*int size, num;*/

	list.insertatstart(1,"talha", 50);
	list.insertatstart(2,"haseeb", 150);
	list.insertatstart(3,"hamza", 250);
	list.insertatstart(4,"sohaib", 350);
	//list.deletehead();
	list.arrangeaccending();
	//list.deletehead();
	list.print();

	// list.insertatend(3);
	// list.insertatend(2);
	// list.insertatend(1);
	// list.deleteend();
	// list.deleteend();
	// list.print();
	//	
	//	cout<<"Enter the size of your linked list : ";
	//	cin>>size;
	//	cout<<"Enter numbers at start"<<endl;
	//	for(int i=0; i<size; i++){
	//		cout<<"Enter new num : ";
	//		cin>>num;
	//		list.insertatstart(num);
	//		cout<<"The list now is : "<<endl;
	//		list.print();
	//		cout<<"\n";
	//	}
	//	
	//	cout<<"Enter numbers at end now: ";
	//	for(int i=0; i<size; i++){
	//		cout<<"Enter new num : ";
	//		cin>>num;
	//		list.insertatend(num);
	//		cout<<"The list now is : "<<endl;
	//		list.print();
	//		cout<<"\n";
	//	}
	return 0;
}
