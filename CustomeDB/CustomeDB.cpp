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
#include <string>
using namespace std;

struct Node {
    int price;
    string ID;
    string name;
    Node* next;
};

struct Node* head = NULL;


void insert(int prc, string nme, string id) {
    struct Node* newNode = new Node;
    newNode->price = prc;
    newNode->name = nme;
    newNode->ID = id;
    newNode->next = head;
    head = newNode;
}

void print() {
    struct Node* temp = head;
    while (temp != NULL) {
        cout << endl;
        cout << "The price is :- " << temp->price << endl;
        cout << "The name of the product is :- " << temp->name << endl;
        cout << "The ID of the product is :- " << temp->ID << endl;
        temp = temp->next;
    }
}


void deletehead() {
    if (head == NULL) {
        cout << "Empty" << endl;
    }
    else {
        cout << endl;
        cout << head->price << " is removed." << endl;
        cout << head->name << " is removed." << endl;
        cout << head->ID << " is removed." << endl;
        head = head->next;
    }

    //    void update_data(int old_price,int new_price) {
    //        int pos = 0;
    //
    //        if (head == NULL) {
    //            cout << "Linked list empty" << endl;
    //        }
    //
    //        current = head;
    //        while (current->next != NULL) {
    //            if (current->price == old_price) {
    //                current->data = new_price;
    //                cout << "Updated!!!" << endl;
    //            }
    //
    //            current = current->next;
    //        }
    //        cout << "not present" << endl;
    //    }
    //}


    int main() {
        string p, c;
        int a, entry = 0;
        cout << "How many entries you wanna do L" << endl;
        cin >> entry;

        for (int i = 0;i < entry;i++) {
            cout << "Enter the product then enter its price and lastly its ID" << endl;
            cin >> p;
            cin >> a;
            cin >> c;
            insert(a, p, c);
        }
        print();
        deletehead();
        print();
        //update_data();
        //print();

        return 0;
    }

////////////////////////////////////////////////////////