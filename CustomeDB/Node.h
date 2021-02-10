#pragma once
#include <string>
#include "Employee.h"
#include "client.h"
#include "Project.h"

using namespace std;

class Node {
public:

    Client client;
    Project prj;
    Node();
    
    Node(string name, int id, string salary, string project, string joiningDate, string phone, string address);
    Node(string name, int id, string phone, string address, string project_id);
    Node(int id, string name, string description, string money_earned, string deadline, string complete_date, string client_id);

    Node* next;
	Employee emp;

    Employee getEmployee();
    Client getClient();
    Project getProject();
};



