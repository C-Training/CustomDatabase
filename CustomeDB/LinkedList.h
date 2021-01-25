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

    LinkedList();
    LinkedList(string fileName);
    ~LinkedList();
    


    Node *getempHead();
    Node *getclientHead();

    void addAtHead(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtHead(string name, int id, string phone, string address, int project_id);

    void addAtEnd(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtEnd(string name, int id, string phone, string address, int project_id);

    void deleteAtEmpHead();
    void deleteAtHead();

    void deleteById(int id);
    void deleteById(int id);

    void displayEmpList();
    void displayList();

    void updateSalary(int id, string name, double new_salary);


    void swapEmpNodes(Node* cur, Node* index);
    void swapNodes(Node* cur, Node* index);

    void sortByEmpNameAes();
    void sortByNameAes();

    void sortByEmpNameDec();
    void sortByNameDec();

    size_t listEmpSize();
    size_t listSize();

    void reverseEmpLinkedList();
    void reverseLinkedList();

};

