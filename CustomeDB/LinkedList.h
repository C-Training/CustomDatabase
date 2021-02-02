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
    //void deleteAtHead();
    void deleteAtHead();
    void deleteAtHeadPrj();

    void deleteAtEndPrj();

    void deleteById(int id);
    //void deleteById(int id);
    void deleteByIdPrj(int id);
    void displayList();
    //void displayList();
    void displayListPrj();

    void updateSalary(int id, string name, double new_salary);


    //void swapNodes(Node* cur, Node* index);
    

    //void sortByNameAes();


    //void sortByNameDec();
 

    //size_t listSize();
    size_t listSize();
    size_t listSizeProj();

    //void reverseLinkedList();
    void reverseLinkedList();

};

