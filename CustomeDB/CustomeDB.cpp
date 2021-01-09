#include<iostream>
using namespace std;

class list1 {
public:
	int data;
	list1* next;
	int key;
	list1() {
		data = 0;
		next = NULL;
		key = 0;

	}

};

class linkList {
public:
	list1* head;
	list1* current;
	linkList() {
		head = NULL;
		current = NULL;
	}
	void addNodeAtEnd(int num) {
		list1* n = new list1();
		n->data = num;
		n->key = n->key + 1;

		if (head == NULL) {
			head = n;
			current = n;
		}
		else {
			current->next = n;
			current = n;
		}
	}
	void deleteNodeFromStart() {
		if (head == NULL) {
			cout << "No Data Found" << endl;
		}
		else {
			list1* temp;
			temp = head->next;
			head = temp;
		}
	}

	void deleteAnyNode(int dataOfNodeToDelete) {
		if (checkNumber(dataOfNodeToDelete))
		{
			if (head == NULL) {
				cout << "No value to delete" << endl;
			}

			else {
				list1* f;
				list1* b;
				int counter = 0;
				f = head;
				b = head;
				while (f->data != dataOfNodeToDelete)
				{
					f = f->next;
					counter++;
				}
				if (counter <= 0)
				{
					deleteNodeFromStart();
				}
				else {
					for (int i = 1; i < counter; i++) {
						b = b->next;
					}
					b->next = f->next;
				}
			}
		}
		else
		{
			cout << "Number Does Not Exist" << endl;
		}


	}
	void updateAnyValue(int whichValueToUpdate, int value) {
		if (head == NULL)
		{
			cout << "No Vale to Update" << endl;
		}
		if (checkNumber(whichValueToUpdate))
		{

			list1* temp;
			temp = head;
			while (temp->data != whichValueToUpdate)
			{
				temp = temp->next;
			}
			temp->data = value;
		}
		else
		{
			cout << "Number Do Not Exist" << endl;
		}
	}
	bool checkNumber(int num) {
		list1* temp;
		temp = head;
		bool myflag = false;

		while (temp->next != NULL)
		{
			if (temp->data == num)
			{
				myflag = true;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
		if (temp->data == num) {
			myflag = true;
		}
		return myflag;


	}


	void sortAccending() {
		list1* p;
		list1* q;
		list1* temp;
		int counter = 1;
		p = head;
		q = head->next;
		temp = head;
		int mycounter = 0;

		while (temp->next != NULL)
		{
			temp = temp->next;
			counter++;
		}
		for (int i = 0; i < counter; i++)
		{

			mycounter = i;
			for (int j = mycounter + 1; j < counter; j++)
			{
				int valp;
				if (q->next != NULL && p->next != NULL) {
					if (p->data >= q->data)
					{
						valp = p->data;
						p->data = q->data;
						q->data = valp;
					}
					q = q->next;

				}
				else {
					if (q->next == NULL)
					{
						if (p->data >= q->data)
						{
							valp = p->data;
							p->data = q->data;
							q->data = valp;
						}
					}
				}
				mycounter++;

			}
			if (p->next != NULL)
			{
				p = p->next;
				q = p->next;
			}

		}

	}
	void ReverseList() {
		if (head != NULL)
		{
			list1* f;
			list1* b;
			list1* temp;
			int mycounter = 0;
			f = head->next;
			b = head;
			temp = head;
			while (f->next != NULL)
			{
				//f = f->next;
				temp = f->next;
				f->next = b;
				b = f;
				//b = b->next;
				f = temp;
			}
			f->next = b;
			head->next = NULL;
			head = temp;

		}
		else {
			cout << "No item found" << endl;
		}

	}

	void showAllElements() {
		if (head != NULL)
		{
			int counter = 1;
			list1* temp = head;
			while (temp->next != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
				counter++;
			}
			cout << temp->data << endl;
			cout << "Length of Link List is: " << counter << endl;
		}
		else
		{
			cout << "No Element Found" << endl;
		}

	}

};

int main() {
	linkList obj;


	for (int i = 0; i < 5; i++) {
		obj.addNodeAtEnd(rand() % 100);
	}
	obj.showAllElements();

	cout << "Enter The Value you want to delete" << endl;
	int valueTodelete, valToUpadte, newValueToUpdate;
	cin >> valueTodelete;
	obj.deleteAnyNode(valueTodelete);
	obj.showAllElements();
	cout << "Enter The value to update" << endl;
	cin >> valToUpadte;
	cout << "Enter The New Value" << endl;
	cin >> newValueToUpdate;
	obj.updateAnyValue(valToUpadte, newValueToUpdate);
	obj.showAllElements();
	cout << "Sorted Array" << endl;
	obj.sortAccending();
	obj.showAllElements();
	cout << "Reversed list : " << endl;
	obj.ReverseList();
	obj.showAllElements();

	return 0;


}