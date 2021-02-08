#pragma once
#include "LinkedList.h"
#include"Display.h"
#include <string>
using namespace std;


class Activity
{
	LinkedList database;
	Employee emp;
	Client cli;
	Project prj;
	Display display;

	void enterToEmployeeDatabase();				//Entering to the database should be a private function and should not be accesed in main
												//It should rather be called inside the setData function;

public:


	void setData(string name, double salary, string project, string joiningDate, string phone, string address);
	void setData(string name, string phone, string address, int project_id);
	void setData(string name, string description, int client_id, string money_earned, string deadline, string complete_date);
	
	void enterToCliDatabase();
	void enterToDatabasePrj();
	
	void deleteEmployee(int id);
	void deleteCliDataById();
	void deleteHeadProjectDatabase();	
	void deleteEndProjectDatabase();
	void deleteByIdPrj(int id);
	
	void updateByIdPrj(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date);
	void updateClientData(string name, int id, string phone, string address, int project_id);
	void updateDatabase(string name, int id, double salary, string project, string joiningDate, string phone, string address);


	void showClientDatabase();
	void displayProjectDatabase();
	void displayEmployeeDatabase();
	bool displayMainMenu();
	bool authFunc(string username, string password);
	void onLoad();
	void crudOperation(int modelOption, int crudOption);
	void createOperation(int modelOption);
	void readOperation(int modelOption);
	void updateOperation(int modelOption);
	void deleteOperation(int modelOption);
};

	



