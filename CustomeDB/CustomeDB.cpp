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
    Node(int id, string name, int price) {
        this->data.id = id;
        this->data.name = name;
        this->data.price = price;
    }
    Item data;
    Node* next;
};

class LinkedList {
    Node* head = NULL;
public:
    void addAtEnd(int id, string name, int price) {

        Node* new_node = new Node(id, name, price);
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
            Node* temp = head;
            head = head->next;
            delete temp;
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

    void swapNodes(Node* cur, Node* index) {
        Item temp;
        temp.id = cur->data.id;
        temp.name = cur->data.name;
        temp.price = cur->data.price;
        cur->data.id = index->data.id;
        cur->data.name = index->data.name;
        cur->data.price = index->data.price;
        index->data.id = temp.id;
        index->data.name = temp.name;
        index->data.price = temp.price;
    }

    void sortByNameAes() {
        Node* cur = head;
        Node* index = NULL;
        if (head == NULL) {
            cout << "Linked list empty, nothing to sort \n";
        }
        else {
            while (cur != NULL) {
                index = cur->next;
                while (index != NULL) {
                    if (cur->data.name > index->data.name) {
                        swapNodes(cur, index);
                    }
                    index = index->next;
                }
                cur = cur->next;
            }
        }
    }

    void sortByNameDec() {
        Node* cur = head;
        Node* index = NULL;
        if (head == NULL) {
            cout << "Linked list empty, nothing to sort \n";
        }
        else {
            while (cur != NULL) {
                index = cur->next;
                while (index != NULL) {
                    if (cur->data.name < index->data.name) {
                        swapNodes(cur, index);
                    }
                    index = index->next;
                }
                cur = cur->next;
            }
        }
    }

    size_t listSize() {
        Node* cur = head;
        size_t counter = 0;
        while (cur != NULL) {
            cur = cur->next;
            counter++;
        }
        return counter;
    }

    void reverseLinkedList() {
        Node* cur = head;
        Node* temp = NULL;
        Node* prev = NULL;
        if (head == NULL) {
            cout << "Linked list empty, nothing to reverse.\n";
        }
        else if (head->next == NULL) {
            cout << "Only one element in List, nothing to reverse.\n";
        }
        else {
            while (cur != NULL) {
                temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            head = prev;
        }
    }

};

int main()
{
    LinkedList l1;

    for (int i = 0; i < 10000000; i++) {
        l1.addAtEnd(1, "talha", 20);
        l1.addAtEnd(2, "haseed", 10);
        l1.addAtEnd(3, "bats", 25);
        l1.displayList();
        l1.deleteAtHead();
        l1.deleteAtHead();
        l1.deleteAtHead();
    }
    return 0;
}
