#include "Display.h"


void Display::showProjectDatabase(LinkedList database) 
{
	database.displayListPrj();
}

void Display::showClientDatabase(LinkedList database)
{
	database.displayCliList();
}

void Display::showEmployee(LinkedList database)
{
	database.displayEmployeeList();

}

