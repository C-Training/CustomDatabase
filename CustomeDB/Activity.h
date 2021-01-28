#pragma once

#include "LinkedList.h"
#include "Display.h"
#include <string>
using namespace std;


class Activity
{
	LinkedList database;
	Employee emp;
	Display display;
	void enterToEmployeeDatabase();				//Entering to the database should be a private function and should not be accesed in main
												//It should rather be called inside the setData function;
public:
	void setData(string name, int id, double salary, string project, string joiningDate, string phone, string address);
	void displayEmployeeDatabase();
	void updateDatabase(string name, int id, double salary, string project, string joiningDate, string phone, string address);
	void deleteEmployee(int id);
};


