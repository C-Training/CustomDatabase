#pragma once

#include "LinkedList.h"
#include <string>
using namespace std;


class Activity
{
	LinkedList database;
	Employee emp;
	Project prj;
public:
	void setData(string name, int id, double salary, string project, string joiningDate, string phone, string address);
	void setData(string name, int id, string description, int client_id, int money_earned, string deadline, string complete_date);
	void enterToDatabasePrj();
	void enterToDatabase();
	void deleteHeadProjectDatabase();
	void deleteEndProjectDatabase();
	
	void displayDatabase();

};
