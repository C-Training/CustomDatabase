#pragma once
#include "LinkedList.h"
#include <string>
using namespace std;

class Activity {
private:
	LinkedList database;
	Client cli;
public:
	void setdata(string name, int cl_id, string phone, string address, int project_id);

	void entertoclidatabase();

	void displaydatabase();
};