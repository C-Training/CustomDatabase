#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

class LinkedList {

    Node* clienthead = NULL;
    Node* emphead = NULL;
    Node* projhead = NULL;

    string fileName;
public:
    LinkedList();

    LinkedList(string fileName);
    ~LinkedList();

    Node *getclientHead();

    void addAtHead(string name, int id, string phone, string address, int project_id);

    void addAtEnd(string name, int id, string phone, string address, int project_id);

    void deleteAtHead();

    void deleteById(int id);

    void displayList();

//    void updatePhone(int old_val, int new_val);

    void swapNodes(Node* cur, Node* index);

    void sortByNameAes();

    void sortByNameDec();

    size_t listSize();

    void reverseLinkedList();

};

