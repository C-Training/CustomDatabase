#pragma once

#include "LinkedList.h"
#include <string>
using namespace std;

class Activity
{
	LinkedList database;
  Client cli;
	Employee emp;
public:
	void setData(string name, int id, double salary, string project, string joiningDate, string phone, string address);
	void setdata(string name, int cl_id, string phone, string address, int project_id);
  
  void enterToDatabase();
  void entertoclidatabase();
	
  void displayDatabase();
  void displaydatabase();
};


