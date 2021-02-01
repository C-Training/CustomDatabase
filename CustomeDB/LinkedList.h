#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

class LinkedList {

    Node* clienthead = NULL;
    Node* prjhead = NULL;
    Node* prjtail = NULL;

    string fileName;
public:

    LinkedList();
    LinkedList(string fileName);
    ~LinkedList();

    Node *getclientHead();
    Node *getProjectHead();
    

    void addAtHead(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtHead(string name, int id, string phone, string address, int project_id);
    void addAtHead(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);
    void addAtEnd(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void addAtEnd(string name, int id, string phone, string address, int project_id);
    void addAtEnd(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);

    void deleteAtCliHead();

    void deleteById();

    void displayCliList();

    void updateClient(string name, int id, string phone, string address, int project_id);

    void swapCliNodes(Node* cur, Node* index);

    void sortByCliNameAes();
    
    
    void updateByIdPrj(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);
    
    
    void deleteAtHeadPrj();

    void sortByCliNameDec();
    void deleteAtEndPrj();

    
    
    void deleteByIdPrj(int id);
    
    
    void displayListPrj();
    size_t ClilistSize();

    void deleteAtEmployeeHead();
    void deleteAtHead();
    void deleteAtCliHead();

    
    void deleteByCliId();
    void deleteByEmployeeId(int id);
    void deleteByPrjId(int id);
    void deleteById(int id);

    void displayEmployeeList();
    void displayCliList();

    void reverseCliLinkedList();
    void displayList();

    void updateSalary(int id, string name, double new_salary);

    void updateEmployee(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    void updateCliList();


 

    
    size_t listSize();
    size_t listSizeProj();

    void updateClient(string name, int id, string phone, string address, int project_id);

    void swapCliNodes(Node* cur, Node* index);
    void swapEmployeeNodes(Node* cur, Node* index);
    void swapNodes(Node* cur, Node* index);
    

    void sortByEmployeeNameAes();
    void sortByNameAes();
    void sortByCliNameAes();

    void sortByNameDec();
    void sortByCliNameDec();

    size_t employeeListSize();
    

    void reverseEmployeeLinkedList();
    size_t ClilistSize();

    void reverseLinkedList();
    void reverseCliLinkedList();

};
