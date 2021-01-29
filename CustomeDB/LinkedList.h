#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

class LinkedList {

    Node* emphead = NULL;
    Node* clienthead = NULL;
    Node* prjhead = NULL;
    Node* prjtail = NULL;

    string fileName;
public:

    LinkedList();
    LinkedList(string fileName);
    ~LinkedList();

    Node *getempHead();
    Node *getclientHead();
    Node *getProjectHead();
    

    void addAtHead(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtHead(string name, int id, string phone, string address, int project_id);
    void addAtHead(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);
    void addAtEnd(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtEnd(string name, int id, string phone, string address, int project_id);
    void addAtEnd(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);


    
    
    void updateByIdPrj(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);
    
    
    void deleteAtHeadPrj();

    void deleteAtEndPrj();

    
    
    void deleteByIdPrj(int id);
    
    
    void displayListPrj();

    void deleteAtEmployeeHead();
    void deleteAtHead();
    void deleteAtCliHead();

    
    void deleteByCliId();
    void deleteByEmployeeId(int id);
    void deleteByPrjId(int id);
    void deleteById(int id);

    void displayEmployeeList();
    void displayCliList();


    void updateSalary(int id, string name, double new_salary);

    void updateEmployee(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void updateCliList();


 

    
    size_t listSize();
    size_t listSizeProj();

    void updateCliList();
    void updateClient(string name, int id, string phone, string address, int project_id);

    void swapCliNodes(Node* cur, Node* index);
    void swapEmployeeNodes(Node* cur, Node* index);
    void swapNodes(Node* cur, Node* index);
    

    void sortByEmployeeNameAes();
    void sortByNameAes();
    void sortByCliNameAes();

    void sortByEmployeeNameDec();
    void sortByNameDec();
    void sortByCliNameDec();

    size_t employeeListSize();
    

    void reverseEmployeeLinkedList();
    size_t ClilistSize();

    void reverseLinkedList();
    void reverseCliLinkedList();

};
