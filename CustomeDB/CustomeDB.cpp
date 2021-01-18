#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;


class shop {
private:
	int id;
	string name;
	int price;

public:

	void setid(int id) {
		this->id = id;
	}

	void setname(string name) {
		this->name = name;
	}

	void setprice(int price) {
		this->price = price;
	}

	int getid() {
		return id;
	}

	string getname() {
		return name;
	}

	int getprice() {
		return price;
	}
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
		temp->s.setid(x);
		temp->s.setname(y);
		temp->s.setprice(z);
		temp->next = head;
		head = temp; 
	}

	void insertatend(int x, string y, int z) {
		node* temp = new node;
		temp->s.setid(x); 
		temp->s.setname(y);
		temp->s.setprice(z);
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
				if (curr->s.getname() > temp->s.getname()) {
					a = curr->s.getid();
					c = curr->s.getname();
					b = curr->s.getprice();

					curr->s.setid(temp->s.getid());
					curr->s.setname(temp->s.getname());
					curr->s.setprice(temp->s.getprice());

					temp->s.setid(a); 
					temp->s.setname(c); 
					temp->s.setprice(b); 
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
					if (curr->s.getname() < temp->s.getname()) {
						a = curr->s.getid();
						c = curr->s.getname();
						b = curr->s.getprice();

						curr->s.setid(temp->s.getid());
						curr->s.setname(temp->s.getname());
						curr->s.setprice(temp->s.getprice());

						temp->s.setid(a);
						temp->s.setname(c);
						temp->s.setprice(b);
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

	void display() {

		int option;
		node* temp = head;
		cout << "Press 1 to read and 2 to write in the file : ";
		cin >> option;
		if (option == 1) {
			ifstream read("MyDatabase.txt");
			if (!"MyDatabase.txt") {
				cout << "File not found \n";
			}
			else {
				int id, price;
				string name;
				while (read >> id >> name >> price) {
					insertatend(id, name, price);
				}
			}
			read.close();
		}
		else if (option == 2) {
			ofstream write;
			write.open("MyDatabase.txt");
			while (temp != NULL) {

				write << temp->s.getid() << " ";
				write << temp->s.getname() << " ";
				write << temp->s.getprice() << " \n";
				temp = temp->next;
			}

			write.close();
		}
		else {
			cout << "Wrong option";
		}
	}



	void print() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->s.getid() << " ";
			cout << temp->s.getname() << " ";
			cout << temp->s.getprice() << " ";
			cout << "\n";
			temp = temp->next;
		}
	}
};


int main() {

	linkedlist list;

	list.insertatstart(1,"talha", 50);
	list.insertatstart(2,"haseeb", 150);
	list.insertatstart(3,"hamza", 250);
	list.insertatstart(4,"sohaib", 350);
	list.insertatstart(5,"batman", 450);
	list.reverse();
	//list.display();
	//list.deletehead();
	//list.arrange();
	//list.deletehead();
	list.print();
	//list.size();

	return 0;
}
