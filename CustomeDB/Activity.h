#pragma once

#include "LinkedList.h"
#include <string>
using namespace std;


class Activity
{
	LinkedList database;
	Employee emp;
	Client cli;
public:
	void setData(string name, int id, double salary, string project, string joiningDate, string phone, string address);
	void setData(string name, int id, string phone, string address, int project_id);

	void enterToDatabase();
	void enterToCliDatabase();
	
	void updateClientData(string name, int id, string phone, string address, int project_id);

	void deleteCliDataById();

	void displayCliList();
};
