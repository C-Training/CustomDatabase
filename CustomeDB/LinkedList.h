#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

class LinkedList {

    
    

    string fileName;
public:

    Node* emphead = NULL;
	Node* clienthead = NULL;
	Node* prjhead = NULL;
	Node* prjtail = NULL;

    LinkedList();
    LinkedList(string fileName);
    ~LinkedList();

    void employeeDatabase();
    void clientDatabase();
    void projectDatabase();

    Node *getempHead();
    Node *getclientHead();
    Node *getProjectHead();
    

    void addAtHead(string name, int id, string salary, string project, string joiningDate, string phone, string address);
    void addAtHead(string name, int id, string phone, string address, string project_id);
    void addAtHead(int id, string name, string description, string money_earned, string deadline, string complete_date, string client_id);
    
    void addAtEnd(string name, int id, string salary, string project, string joiningDate, string phone, string address);
    void addAtEnd(string name, int id, string phone, string address, string project_id);
    void addAtEnd(int id, string name, string description, string money_earned, string deadline, string complete_date, string client_id);

    void deleteAtCliHead();
    void deleteAtHeadPrj();
    void deleteAtEndPrj();
    void deleteAtEmployeeHead();
    
    void deleteByIdPrj(int id);
    void deleteByEmployeeId(int id);
    void deleteByCliId();

    void displayEmployeeList();
    void displayCliList();
    void displayListPrj();


    void updateSalary(int id, string name, string new_salary);
    void updateClient(string name, int id, string phone, string address, string project_id);
    void updateEmployee(string name, int id, string salary, string project, string joiningDate, string phone, string address);
    void updateByIdPrj(int id, string name, string description, string money_earned, string deadline, string complete_date, string client_id);

    void swapEmployeeNodes(Node* cur, Node* index);
    void swapCliNodes(Node* cur, Node* index);

    void sortByEmployeeNameAes();
    void sortByCliNameAes();

    void sortByEmployeeNameDec();
    void sortByCliNameDec();

    size_t employeeListSize();
    size_t ClilistSize();
    size_t listSizeProj();

    void reverseEmployeeLinkedList();
    void reverseCliLinkedList();

};



