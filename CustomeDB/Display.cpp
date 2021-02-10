#include "Display.h"


void Display::showProjectDatabase(LinkedList database) 
{
	database.displayListPrj();
}

void Display::showClientDatabase(LinkedList database)
{
	database.displayCliList();
}

void Display::showMenu()
{
	cout << "MENU" << endl;
	cout << "Welcome to SRS Management System" << endl;
	cout << "Login" << endl;
}

void Display::showHome()
{
	cout << "Home" << endl;
	cout << "SELECT AN OPTION" << endl;
	cout << "1: Employee" << endl;
	cout << "2: CLient" << endl;
	cout << "3: Project" << endl;
	cout << "Enter 4 to Leave" << endl;
}

void Display::showCRUD(string obj)
{
	system("CLS");
	cout << "SELECT AN OPTION" << endl;
	cout << "1: Create " << obj << endl;
	cout << "2: Read " << obj << endl;
	cout << "3: Update " << obj << endl;
	cout << "4: Delete " << obj << endl;
	cout << "5: Main Menu "<< endl;
	cout << "6: Exit Program " << endl;
}

void Display::showEmployee(LinkedList database)
{
	database.displayEmployeeList();
}

