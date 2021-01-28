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

    void deleteAtEmployeeHead();
    void deleteAtHead();

    void deleteByEmployeeId(int id);
    void deleteById(int id);

    void displayEmployeeList();
    void displayList();

    void updateSalary(int id, string name, double new_salary);

    void updateEmployee(string name, int id, double salary, string project, string joiningDate, string phone, string address);

    void swapEmployeeNodes(Node* cur, Node* index);
    void swapNodes(Node* cur, Node* index);

    void sortByEmployeeNameAes();
    void sortByNameAes();

    void sortByEmployeeNameDec();
    void sortByNameDec();

    size_t employeeListSize();
    size_t listSize();

    void reverseEmployeeLinkedList();
    void reverseLinkedList();

};

