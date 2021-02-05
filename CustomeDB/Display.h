#pragma once
#include"LinkedList.h"
#include <iostream>
#include"Node.h"
#include"Project.h"
using namespace std;

class Display{
public:	

	void showProjectDatabase(LinkedList database);
	void showEmployee(LinkedList);
	void showClientDatabase(LinkedList);
	void showMenu();
	void showHome();
	void showCRUD(string obj);

};






