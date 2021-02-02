#pragma once

#include "LinkedList.h"
#include"Display.h"
#include <string>
using namespace std;


class Activity
{
	LinkedList database;
	Employee emp;
	Project prj;
	Display dis;
	
public:


	void setData(string name, int id, double salary, string project, string joiningDate, string phone, string address);
	void setData(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);
	void enterToDatabasePrj();
	void enterToDatabase();
	void deleteHeadProjectDatabase();	
	void deleteEndProjectDatabase();
	void deleteByIdPrj(int id);
	void updateByIdPrj(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);
	
	void display();

	void displayDatabase();

};
