#pragma once

#include "LinkedList.h"
#include <string>
using namespace std;


class Activity
{
	LinkedList database;
	Employee emp;
public:
	void setData(string name, int id, double salary, string project, string joiningDate, string phone, string address);
	void enterToDatabase();
	void displayDatabase();
};

