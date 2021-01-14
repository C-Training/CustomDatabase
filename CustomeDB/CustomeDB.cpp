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

	void arrange() {
		cout << "Press 1 to arrange in ascending order \n";
		cout << "Press 2 to arrange in descending order \n";
		int input, a, b;
		string c;
		node* temp = NULL;
		node* curr = head;

		cin >> input;
		
		if(input==1){

		while (curr != NULL) {
			temp = curr->next;
			while (temp != NULL) {
				if (curr->s.name > temp->s.name) {
					a = curr->s.id;
					c = curr->s.name;
					b = curr->s.price;

					curr->s.id = temp->s.id;
					curr->s.name = temp->s.name;
					curr->s.price = temp->s.price;

					temp->s.id = a;
					temp->s.name = c;
					temp->s.price = b;
			}
				temp = temp->next;

			}
			curr = curr->next;
}
	}
		else if (input == 2) {

			while (curr != NULL) {
				temp = curr->next;
				while (temp != NULL) {
					if (curr->s.name < temp->s.name) {
						a = curr->s.id;
						c = curr->s.name;
						b = curr->s.price;

						curr->s.id = temp->s.id;
						curr->s.name = temp->s.name;
						curr->s.price = temp->s.price;

						temp->s.id = a;
						temp->s.name = c;
						temp->s.price = b;
					}
					temp = temp->next;

				}
				curr = curr->next;
			}
		}
		else {
			cout << "Choose Either 1 or 2 ";
		}
}

	void reverse() {
		node* current= head;
		node* prev = NULL;
		node* temp;
		while (current!=NULL){
			temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
		head = prev; 
	}

	void size() {
		int count = 0;
		node* temp = head;
		while (temp != NULL) {
			temp = temp->next;
			count++;
		}
		cout<<"Size of the list is :"<< count<<endl;
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


int main() {

	linkedlist list;
	/*int size, num;*/

	list.insertatstart(1,"talha", 50);
	list.insertatstart(2,"haseeb", 150);
	list.insertatstart(3,"hamza", 250);
	list.insertatstart(4,"sohaib", 350);
	list.reverse();
	//list.deletehead();
	//list.arrange();
	//list.deletehead();
	list.print();
	//list.size();

	return 0;
}
