#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

class LinkedList {
    Node* head = NULL;
    string fileName;
public:
    LinkedList();

    LinkedList(string fileName);
    ~LinkedList();

    void addAtHead(int id, string name, int price);

    void addAtEnd(int id, string name, int price);

    void deleteAtHead();

    void deleteById(int id);

    void displayList();

    void updatePrice(int old_val, int new_val);

    void swapNodes(Node* cur, Node* index);

    void sortByNameAes();

    void sortByNameDec();

    size_t listSize();

    void reverseLinkedList();

};

