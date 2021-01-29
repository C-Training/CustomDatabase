#include "Display.h"


void Display::showProjectDatabase(LinkedList database) 
{
	database.displayListPrj();
}

void Display::showEmployee(LinkedList database)
{
	database.displayEmployeeList();

}

void Display::showClient(LinkedList database)
{
	database.displayCliList();
}
