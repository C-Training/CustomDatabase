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



    Node* getempHead();
    Node* getclientHead();

    void addAtHead(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtHead(string name, int cl_id, string phone, string address, int project_id);

    void addAtEnd(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtEnd(string name, int cl_id, string phone, string address, int project_id);

    void deleteAtHead();
    void deleteAtcliHead();

    void deleteById(int id);
    void deleteBycliId(int cl_id);

    void displayList();
    void displaycliList();

    void updateSalary(int id, string name, double new_salary);


    void swapNodes(Node* cur, Node* index);
    void swapcliNodes(Node* cur, Node* index);

    void sortByNameAes();
    void sortBycliNameAes();

    void sortByNameDec();
    void sortBycliNameDec();

    size_t listSize();
    size_t clilistSize();

    void reverseLinkedList();
    void reversecliLinkedList();

};

