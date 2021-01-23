#pragma once
#include "LinkedList.h"
#include <string>
using namespace std;

class Acitivity {
private:
	LinkedList database;
	Client cli;
public:
	void setdata(string name, int id, string phone, string address, int project_id);

	void entertodatabase();

	void displaydatabase();
};