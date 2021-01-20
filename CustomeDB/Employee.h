#pragma once
#include <iostream>

using namespace std;

class Employee
{
	string name;
	int id;
	double salary;
	string project;
	string joiningDate;
	string phone;
	string address;
public:

	void setName(string name);
	string getName();
	void setId(int id);
	int getId();
	void setSalary(double salary);
	double getSalary();
	void setProject(string project);
	string getProject();
	void setJoiningDate(string joiningDate);
	string getJoiningDate();
	void setPhone(string phone);
	string getPhone();
	void setAddress(string address);
	string getAddress();
};

