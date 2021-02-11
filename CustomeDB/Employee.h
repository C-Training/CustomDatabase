#pragma once
#include <iostream>

using namespace std;

class Employee
{
	string name;
	
	int id = 0;
	string salary;
	string project;
	string joiningDate;
	string phone;
	string address;
public:
	static int counter;
	void setName(string name);
	string getName();
	void setId(int id);
	int getId();
	void setSalary(string salary);
	string getSalary();
	void setProject(string project);
	string getProject();
	void setJoiningDate(string joiningDate);
	string getJoiningDate();
	void setPhone(string phone);
	string getPhone();
	void setAddress(string address);
	string getAddress();
};




