#pragma once
#include "LinkedList.h"
#include "Display.h"
#include<conio.h>
#include <string>
#include<limits>
#include<cctype>
#include<regex>
#include<fstream>
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


	void setData(string name, string salary, string project, string joiningDate, string phone, string address);
	void setData(string name, string phone, string address, string project_id);
	void setDataProject(string name, string description, string money_earned, string deadline, string complete_date, string client_id);
	
	void enterToCliDatabase();
	void enterToDatabasePrj();
	
	void deleteEmployee(int id);
	void deleteCliDataById();
	void deleteHeadProjectDatabase();	
	void deleteEndProjectDatabase();
	void deleteByIdPrj(int id);
	
	bool is_empty(ifstream& pFile);

	void updateByIdPrj(int id, string name, string description, string money_earned, string deadline, string complete_date, string client_id);
	void updateClientData(string name, int id, string phone, string address, string project_id);
	void updateDatabase(string name, int id, string salary, string project, string joiningDate, string phone, string address);


	void showClientDatabase();
	void displayProjectDatabase();
	void displayEmployeeDatabase();
	bool displayMainMenu();
	bool authFunc(string username, string password);
	LinkedList loadEmpDatabase();
	LinkedList loadCliDatabase();
	LinkedList loadPrjDatabase();
	void onLoad();
	void crudOperation(string modelOption, string crudOption);
	void createOperation(string modelOption);
	void readOperation(string modelOption);
	void updateOperation(string modelOption);
	void deleteOperation(string modelOption);
};



	



