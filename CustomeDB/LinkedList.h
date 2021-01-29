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

    void deleteAtHead();
    void deleteAtCliHead();

    void deleteById(int id);
    void deleteById();

    void displayEmployeeList();
    void displayCliList();

    void updateSalary(int id, string name, double new_salary);
    void updateClient(string name, int id, string phone, string address, int project_id);

    void swapNodes(Node* cur, Node* index);
    void swapCliNodes(Node* cur, Node* index);

    void sortByNameAes();
    void sortByCliNameAes();

    void sortByNameDec();
    void sortByCliNameDec();

    size_t listSize();
    size_t ClilistSize();

    void reverseLinkedList();
    void reverseCliLinkedList();

};
