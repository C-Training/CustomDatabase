#pragma once
#include <string>
#include "Employee.h"
#include "client.h"
#include "Project.h"

using namespace std;

class Node {
private:
    Client client;
    
public:


    Project prj;
    Node();
    
    Node(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    Node(string name, int id, string phone, string address, int project_id);
    Node(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);

    Node* next;

	
 
    
	Employee emp;

    Employee getEmployee();
    Client getClient();
    Project getProject();
};

