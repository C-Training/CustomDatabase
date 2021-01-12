#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include "node.h"
using namespace std;

class linkedlist {
public:
    void insert(int prc, string nme, int id) {
        struct Node* newNode = new Node;
        newNode->price = prc;
        newNode->name = nme;
        newNode->ID = id;
        newNode->next = head;
        head = newNode;
    }

    void update_data(int id, int new_price) {
        struct Node* temp = head;
        while ((temp->ID) != id) {
            temp = temp->next;
        }
        temp->price = new_price;
        cout << "New price of " << (temp->ID) << "is " << (temp->price) << endl;
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

    void display() {
        int a = 0;
        string myText;
        struct Node* temp = head;
        cout << endl;
        cout << "1 to write in new file and 2 to display contents of old file" << endl;
        cin >> a;
        if (a == 1) {
            ofstream MyFile("L.txt");
            while (temp != NULL) {
                MyFile << "Name is " << temp->name << endl;
                MyFile << "Price is " << temp->price << endl;
                MyFile << "ID is " << temp->ID << endl;
                temp = temp->next;
            }
            MyFile.close();
        }
        else if (a == 2) {
            ifstream MyReadFile("L.txt");
            while (getline(MyReadFile, myText)) {
                cout << myText << endl;
            }
            MyReadFile.close();
        }
    }

    void reverse() {
        struct Node* temp = head;
        struct Node* next = head;
        struct Node* prev = NULL;

        while (temp != NULL) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        head = prev;
    }

    void sort() {
        int a, c, d = 0;
        string k;
        struct Node* temp = NULL;
        struct Node* current = head;

        cout << "Press 1 for ascending and 2 for descending" << endl;
        cin >> a;
        if (a == 1) {
            while (current != NULL) {
                temp = current->next;
                while (temp != NULL) {
                    if (current->ID > temp->ID) {
                        c = current->ID;
                        k = current->name;
                        d = current->price;
                        current->ID = temp->ID;
                        current->name = temp->name;
                        current->price = temp->price;
                        temp->ID = c;
                        temp->name = k;
                        temp->price = d;
                    }
                    temp = temp->next;
                }
                current = current->next;
            }
        }
        else if (a == 2) {
            while (current != NULL) {
                temp = current->next;
                while (temp != NULL) {
                    if (current->ID < temp->ID) {
                        c = current->ID;
                        k = current->name;
                        d = current->price;
                        current->ID = temp->ID;
                        current->name = temp->name;
                        current->price = temp->price;
                        temp->ID = c;
                        temp->name = k;
                        temp->price = d;
                    }
                    temp = temp->next;
                }
                current = current->next;
            }
        }
        else {
            cout << "Wrong option L" << endl;
        }

    }

    void size() {
        struct Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "The size of the L linked list is " << count << endl;
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

    }
};