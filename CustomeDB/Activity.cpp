#include "Activity.h"

void Activity::setData(string name, string salary, string project, string joiningDate, string phone, string address)
{
	emp.setName(name);
	emp.setId(emp.getId()+1);
	emp.setSalary(salary);
	emp.setProject(project);
	emp.setJoiningDate(joiningDate);
	emp.setPhone(phone);
	emp.setAddress(address);
	enterToEmployeeDatabase();
}

void Activity::setData(string name, string phone, string address, int project_id)
{
	cli.setName(name);
	cli.setId(cli.getId()+1);
	cli.setPhone(phone);
	cli.setAddress(address);
	cli.setProject_Id(project_id);
	enterToCliDatabase();
}

void Activity::setData(string name, string description, int client_id, string money_earned, string deadline, string complete_date) {
	prj.setname(name);
	prj.setid(prj.getid()+1);
	prj.setdescription(description);
	prj.setclient_id(client_id);
	prj.setmoney_earned(money_earned);
	prj.setdeadline(deadline);
	prj.setcomplete_date(complete_date);
	enterToDatabasePrj();
}


void Activity::enterToEmployeeDatabase()
{
	database.addAtEnd(emp.getName(), emp.getId(), emp.getSalary(), emp.getProject(), emp.getJoiningDate(), emp.getPhone(), emp.getAddress());
}

void Activity::enterToCliDatabase() {
	database.addAtEnd(cli.getName(), cli.getId(), cli.getPhone(), cli.getAddress(), cli.getProject_Id());
}

void Activity::deleteEndProjectDatabase() {
	database.deleteAtEndPrj();
}

void Activity::deleteCliDataById() {
	database.deleteByCliId();
}

void Activity::deleteHeadProjectDatabase() {
	database.deleteAtHeadPrj();
}

void Activity::enterToDatabasePrj() {
	database.addAtEnd(prj.getname(), prj.getid(), prj.getdescription(), prj.getclient_id(), prj.getmoney_earned(), prj.getdeadline(), prj.getcomplete_date());
}

void Activity::deleteByIdPrj(int id) {
	database.deleteByIdPrj(id);
}

void Activity::updateByIdPrj(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date) {
	database.updateByIdPrj(name,id,description,client_id,money_earned,deadline,complete_date);
}

void Activity::updateClientData(string name, int id, string phone, string address, int project_id) {
	database.updateClient(name, id, phone, address, project_id);
}

void Activity::displayProjectDatabase(){
	display.showProjectDatabase(database);
}

void Activity::showClientDatabase() {
	display.showClientDatabase(database);
}

void Activity::displayEmployeeDatabase()
{
	display.showEmployee(database);
}

bool Activity::displayMainMenu()
{
	display.showMenu();
	string username;
	string password;
	bool check;
	while (true) {
		cout << "Enter Username" << endl;
		cin >> username;
		cout << "Enter Password" << endl;
		cin >> password;
		check = authFunc(username, password);
		if (check)
			break;
		else
			cout << "username or password incorrect" << endl;
	}
	system("CLS");
	return check;
}

void Activity::onLoad(){
	bool check = displayMainMenu();
	while (check)
	{
		display.showHome();
		string option;
		string crudOption;
		cin >> option;
		if (option == "1") {
			display.showCRUD("Employee");
			cin >> crudOption;
		}
		else if (option == "2") {
			display.showCRUD("CLient");
			cin >> crudOption;
		}
		else if (option == "3") {
			display.showCRUD("Project");
			cin >> crudOption;
		}
		else if (option == "4")
			break;
		else {
			cout << "The option you entered is incorrect" << endl;
			continue;
		}
		system("CLS");
		crudOperation(option, crudOption);
	}

}

void Activity::crudOperation(string modelOption, string crudOption)
{
	if (crudOption == "1") {
		createOperation(modelOption);
	}
	else if(crudOption == "2") {
		readOperation(modelOption);
	}
	else if (crudOption == "3") {
		updateOperation(modelOption);
	}
	else if (crudOption == "4") {
		deleteOperation(modelOption);
	}
	else {
		cout << "Your CRUD option is incorrect" << endl;
	}
}

void Activity::createOperation(string modelOption)
{
	if (modelOption == "1") {
		cout << "Enter Employee Details" << endl;
		cout << "Enter Name:\n";
		cin.ignore();
		string name = "";
		getline(cin, name);
		while (1)
		{
			bool isEqual = false;
			for (int i = 48; i <= 57; i++) {
				if (name[0] == i) {
					isEqual = true;
					break;
				}
			}
			if (isEqual || name == "") {
				cout << "Name cannot start with a Number or be empty, Please Enter Name Again\n";
				getline(cin, name);
			}
			else {
				break;
			}
		}
		string salary;
		cout << "Enter Salary:" << endl;
		cin >> salary;
		regex str_expr("[0-9]|[0-9]+\.[0-9]+");
		while (1) {
			if (regex_match(salary, str_expr)) {
				bool isEqual = false;
				for (int i = 32; i <= 64; i++) {
					if (i >= 48 && i <= 57) {
						continue;
					}
					for (int j = 0; j < salary.size(); j++) {
						if (salary[0] == i) {
							isEqual = true;
							break;
						}
					}
					if (isEqual) {
						break;
					}
				}
				if (isEqual) {
					cout << "Salary cannot hav a symbol! or be empty, Please Enter Salary Again\n";
					cin >> salary;
				}
				break;
			}
			else {
				cout << "Invalid Salary, enter again" << endl;
				cin >> salary;
			}
		}
		string project;
		cout << "Enter Project:" << endl;
		cin >> project;
		string joiningDate;
		cout << "Enter Joining Date:" << endl;
		cin >> joiningDate;
		string phone;
		cout << "Enter Phone Number:" << endl;
		cin >> phone;
		string address;
		cout << "Enter Address:" << endl;
		cin >> address;
		setData(name, salary, project, joiningDate, phone, address);
		database.employeeDatabase();
	}
	else if (modelOption == "2") {
		cout << "Enter Client Details" << endl;
		string name = "";
		cout << "Enter Name:" << endl;
		cin.ignore();
		getline(cin, name);
		while (1)
		{
			bool isEqual = false;
			for (int i = 48; i <= 57; i++) {
				if (name[0] == i) {
					isEqual = true;
					break;
				}
			}
			if (isEqual || name == "") {
				cout << "Name cannot start with a Number or be empty, Please Enter Name Again\n";
				getline(cin, name);
			}
			else {
				break;
			}
		}
		string phone;
		cout << "Enter Phone:" << endl;
		cin >> phone;
		string address;
		cout << "Enter Address:" << endl;
		cin >> address;
		int project_id;
		cout << "Enter Project_ID:" << endl;
		cin >> project_id;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input, Enter Project_ID again." << endl;
				cin >> project_id;
			}
			if (!cin.fail())
				break;
		}
		setData(name, phone, address, project_id);
		database.clientDatabase();
	}
	else if (modelOption == "3") {
		cout << "Enter Project Details" << endl;
		string name = "";
		cout << "Enter Name:" << endl;
		cin.ignore();
		getline(cin, name);
		while (1)
		{
			bool isEqual = false;
			for (int i = 48; i <= 57; i++) {
				if (name[0] == i) {
					isEqual = true;
					break;
				}
			}
			if (isEqual || name == "") {
				cout << "Name cannot start with a Number or be empty, Please Enter Name Again\n";
				getline(cin, name);
			}
			else {
				break;
			}
		}
		string description;
		cout << "Enter description" << endl;
		cin >> description; //getline()
		int client_id;
		cout << "Enter Client_ID" << endl;
		cin >> client_id;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input, Enter Client_ID Again." << endl;
				cin >> client_id;
			}
			if (!cin.fail())
				break;
		}
		string money_earned;
		cout << "Enter money earned:" << endl;
		cin >> money_earned;
		string deadline;
		cout << "Enter Deadline:" << endl;
		cin >> deadline;
		string complete_date;
		cout << "Enter complete date:" << endl;
		cin >> complete_date;
		setData(name, description, client_id, money_earned, deadline, complete_date);
		database.projectDatabase();
	}
}

void Activity::readOperation(string modelOption)
{
	if (modelOption == "1") {
		displayEmployeeDatabase();
	}
	else if (modelOption == "2") {
		showClientDatabase();
	}
	else if (modelOption == "3") {
		displayProjectDatabase();
	}
}

void Activity::updateOperation(string modelOption)
{
	if (modelOption == "1") {
		int id;
		cout << "Enter the ID to update:" << endl;
		cin >> id;
		cout << "Update Employee Details" << endl;
		string name;
		cout << "Enter Name:" << endl;
		cin >> name;
		string salary;
		cout << "Enter Salary:" << endl;
		cin >> salary;
		string project;
		cout << "Enter Project:" << endl;
		cin >> project;
		string joiningDate;
		cout << "Enter Joining Date:" << endl;
		cin >> joiningDate;
		string phone;
		cout << "Enter Phone Number:" << endl;
		cin >> phone;
		string address;
		cout << "Enter Address:" << endl;
		cin >> address;
		updateDatabase(name, id, salary, project, joiningDate, phone, address);
	}
	else if (modelOption == "2") {
		cout << "Update Client Details" << endl;
		int id;
		cout << "Enter ID to Update:" << endl;
		cin >> id;
		string name;
		cout << "Enter Name:" << endl;
		cin >> name;
		string phone;
		cout << "Enter Phone:" << endl;
		cin >> phone;
		string address;
		cout << "Enter Address:" << endl;
		cin >> address;
		int project_id;
		cout << "Enter Project_ID:" << endl;
		cin >> project_id;
		updateClientData(name, id, phone, address, project_id);
	}
	else if (modelOption == "3") {
		cout << "Update Project Details" << endl;
		int id;
		cout << "Enter Project_ID to update:" << endl;
		cin >> id;
		string name;
		cout << "Enter Name:" << endl;
		cin >> name;
		string description;
		cout << "Enter description" << endl;
		cin >> description;
		int client_id;
		cout << "Enter Client_ID" << endl;
		cin >> client_id;
		string money_earned;
		cout << "Enter money earned:" << endl;
		cin >> money_earned;
		string deadline;
		cout << "Enter Deadline:" << endl;
		cin >> deadline;
		string complete_date;
		cout << "Enter complete date:" << endl;
		cin >> complete_date;
		updateByIdPrj(name, id, description, client_id, money_earned, deadline, complete_date);
	}
}

void Activity::deleteOperation(string modelOption)
{
	if (modelOption == "1") {
		cout << "Enter Employee ID to delete" << endl;
		int id;
		cin >> id;
		deleteEmployee(id);
	}
	else if (modelOption == "2") {
		deleteCliDataById();
	}
	else if (modelOption == "3") {
		cout << "Enter Project ID to delete" << endl;
		int id;
		cin >> id;
		deleteByIdPrj(id);
	}
}



bool Activity::authFunc(string username, string password)
{
	if (username == "a" && password == "b")
		return true;
	else
		return false;
}

void Activity::updateDatabase(string name, int id, string salary, string project, string joiningDate, string phone, string address)
{
	database.updateEmployee(name, id, salary, project, joiningDate, phone, address);
}

void Activity::deleteEmployee(int id)
{
	database.deleteByEmployeeId(id);
}



