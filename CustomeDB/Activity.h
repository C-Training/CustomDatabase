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
	
	

	Display display;
	void enterToEmployeeDatabase();				//Entering to the database should be a private function and should not be accesed in main
												//It should rather be called inside the setData function;

	Client cli;
	Display display;
public:


	void setData(string name, int id, double salary, string project, string joiningDate, string phone, string address);
	void setData(string name, int id, string phone, string address, int project_id);

	void enterToCliDatabase();
	
	void updateClientData(string name, int id, string phone, string address, int project_id);

	void deleteCliDataById();


	void setData(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);
	void enterToDatabasePrj();
	void deleteHeadProjectDatabase();	
	void deleteEndProjectDatabase();
	void deleteByIdPrj(int id);
	void updateByIdPrj(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);
	
	void displayProjectDatabase();
	void displayEmployeeDatabase();
	void updateEmployeeDatabase(string name, int id, double salary, string project, string joiningDate, string phone, string address);
	void deleteEmployee(int id);


	void showClientDatabase();
};

	



