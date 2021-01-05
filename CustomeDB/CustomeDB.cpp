// CustomeDB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
    Node* head = NULL;
public:
    void addAtEnd(int val) {

        Node* new_node = new Node();
        new_node->data = val;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
        }
        else {
            Node* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = new_node;
        }

    }
    void deleteAtHead() {
        if (head == NULL) {
            cout << "There is no linked list to delete" << endl;
        }
        else {
            head = head->next;
        }
    }

    void deleteByValue(int x) {
        if (head == NULL) {
            cout << "linked list is empty \n";
        }
        else if (head->data == x) {
            deleteAtHead();
        }
        else {
            Node* cur = head;
            bool found = true;
            while (cur->data != x) {
                if (cur == NULL) {
                    found = false;
                    break;
                }
                cur = cur->next;
            }
            if (found) {
                Node* temp = head;
                while (temp->next != cur) {
                    temp = temp->next;
                }
                temp->next = cur->next;
                delete cur;
            }
            else {
                cout << "val doesnt exist in linked list \n";
            }
        }
    }

    void displayList() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }


};

int main()
{
    LinkedList l1;
    l1.addAtEnd(5);
    l1.addAtEnd(70);
    l1.deleteByValue(5);
    l1.displayList();
    cout << "Talhe here" << endl;

    return 0;
}
/////////////////////////////////////////////////////////////////////
//Hamza was here L
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Node* head = NULL;//intially linked list is empty


void insert(int value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void print() {
    struct Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;//move temp to next node
    }
}


void Delete() {
    if (head == NULL) {
        cout << "Empty" << endl;
    }
    else {
        cout << head->data << " is removed." << endl;
        head = head->next;
    }
}
int main() {

    insert(7);
    insert(5);
    insert(9);
    print();
    //   Delete(); 
    //   display();
    return 0;
}
////////////////////////////////////////////////////////