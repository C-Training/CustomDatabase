#pragma once
#include <string>
#include "Employee.h"

using namespace std;

class Node {
private:
    Employee emp;
public:
	Node();
    Node(string name, int id, double salary, string project, string joiningDate, string phone, string address);
    Node* next;
    Employee getEmployee();
};

