#pragma once
#include <string>
#include "Employee.h"
#include "client.h"

using namespace std;

class Node {
private:
    Client client;
public:
	Node();
    Node(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    Node(string name, int id, string phone, string address, int project_id);
    Node* next;
	Employee emp;
    Employee getEmployee();
    Client getClient();
};

