#include "Display.h"

void Display::showEmployee(LinkedList database)
{
	database.displayEmployeeList();
}

void Display::showClient(LinkedList database)
{
	database.displayCliList();
}