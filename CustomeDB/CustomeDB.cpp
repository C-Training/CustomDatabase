// CustomeDB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Item {
public:
    string name;
    int price;
    int id;
};

class Node {
public:
    Item data;
    Node* next;
};

class LinkedList {
    Node* head = NULL;
public:
    void addAtEnd(int id, string name, int price) {

        Node* new_node = new Node();
        new_node->data.id = id;
        new_node->data.name = name;
        new_node->data.price = price;
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

    void deleteById(int id) {
        if (head == NULL) {
            cout << "linked list is empty \n";
        }
        else if (head->data.id == id) {
            deleteAtHead();
        }
        else {
            Node* cur = head;
            bool found = true;
            while (cur->data.id != id) {
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
                cout << "Id doesnt exist in linked list \n";
            }
        }
    }

    void displayList() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->data.id << " ";
            cout << cur->data.name << " ";
            cout << cur->data.price << " \n";
            cur = cur->next;
        }
        cout << endl;
    }

    void updatePrice(int old_val, int new_val) {
        Node* cur = head;
        bool found = false;
        if (head == NULL) {
            cout << "Linled list is empty" << endl;
        }
        else {
            while (cur != NULL) {
                if (cur->data.price == old_val) {
                    cur->data.price = new_val;
                    found = true;
                    break;
                }
                cur = cur->next;
            }
            if (!found) {
                cout << "Price not found in linked iist.\n";
            }
        }
    }

};

int main()
{
    LinkedList l1;
    l1.addAtEnd(1, "talha", 20);
    l1.addAtEnd(2, "haseed", 10);
    l1.addAtEnd(3, "bats", 25);
    l1.displayList();
    l1.deleteById(1);
    l1.displayList();
    l1.updatePrice(10, 40);
    l1.displayList();

    


    return 0;
}
