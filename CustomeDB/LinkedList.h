#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

class LinkedList {

    Node* emphead = NULL;
    Node* clienthead = NULL;

    string fileName;
public:

    LinkedList(string fileName);
    ~LinkedList();
    LinkedList(string fileName);
    ~LinkedList();


    Node *getempHead();
    Node *getclientHead();

    void addAtHead(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtHead(string name, int id, string phone, string address, int project_id);

    void addAtEnd(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtEnd(string name, int id, string phone, string address, int project_id);

    void deleteAtHead();
    void deleteAtHead();

    void deleteById(int id);
    void deleteById(int id);

    void displayList();
    void displayList();

    void updateSalary(int id, string name, double new_salary);


    void swapNodes(Node* cur, Node* index);
    void swapNodes(Node* cur, Node* index);

    void sortByNameAes();
    void sortByNameAes();

    void sortByNameDec();
    void sortByNameDec();

    size_t listSize();
    size_t listSize();

    void reverseLinkedList();
    void reverseLinkedList();

};

