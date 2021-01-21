#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

class LinkedList {

    Node* emphead = NULL;

    string fileName;
public:

    LinkedList(string fileName);
    ~LinkedList();


    Node *getempHead();

    void addAtHead(string name, int id, double salary, string project, string joiningDate, string phone, string address);

    void addAtEnd(string name, int id, double salary, string project, string joiningDate, string phone, string address);

    void deleteAtHead();

    void deleteById(int id);

    void displayList();

    void updateSalary(int id, string name, double new_salary);

    void swapNodes(Node* cur, Node* index);

    void sortByNameAes();

    void sortByNameDec();

    size_t listSize();

    void reverseLinkedList();

};

