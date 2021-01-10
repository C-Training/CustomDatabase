#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node {
public:
	int data;
	node* next;

	void insertatstart(int x) {

		node* temp = new node;
		temp->data = x;
		temp->next = head;
		head = temp;
	}

	void insertatend(int x) {
		node* temp = new node;
		temp->data = x;
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
			//		node * temp = new node;
			//		temp->next=head;
			head = head->next;
		}
	}

	void deleteend() {
		node* temp = new node;
		if (head == NULL) {
			cout << "Link list is already ded";
		}
		else if (head->next == NULL) {
			head = NULL;
		}
		else {
			temp = head;
			while (temp->next != NULL) {
				tail = temp;
				temp = temp->next;
			}
			tail->next = NULL;
			delete temp;
		}
	}

	void insertatnnode(int data, int pos) {
		node* temp = new node;


	}



	void print() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	node* head = NULL;
	node* tail = NULL;

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

	node list;
	int size, num;

	list.insertatstart(1);
	list.insertatstart(2);
	list.insertatstart(4);
	list.insertatstart(5);
	list.insertatstart(0);
	list.deletehead();
	list.deletehead();
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

}
