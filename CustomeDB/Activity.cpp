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

LinkedList Activity::loadEmpDatabase() {
	string myText;
	string name, a;
	int id;
	string salary;
	string project;
	string joiningDate;
	string phone;
	string address;
	ifstream MyReadFile("Employee.txt");
	LinkedList temp;
	getline(MyReadFile, myText);
	while (!MyReadFile.eof()) {
		getline(MyReadFile, myText);
		name = myText;
		getline(MyReadFile, myText);
		id = stoi(myText);
		getline(MyReadFile, myText);
		salary = myText;
		getline(MyReadFile, myText);
		project = myText;
		getline(MyReadFile, myText);
		joiningDate = myText;
		getline(MyReadFile, myText);
		phone = myText;
		getline(MyReadFile, myText);
		address = myText;
		temp.addAtEnd(name, id, salary, project, joiningDate, phone, address);
	}
	
	MyReadFile.close();
	return temp;
}

LinkedList Activity::loadCliDatabase() {
	string myText;
	string name;
	int id,project_id;
	string phone;
	string address;
	ifstream MyReadFile("Client.txt");
	LinkedList temp;
	getline(MyReadFile, myText);
	while (!MyReadFile.eof()) {
		getline(MyReadFile, myText);
		name = myText;
		getline(MyReadFile, myText);
		id = stoi(myText);
		getline(MyReadFile, myText);
		phone = myText;
		getline(MyReadFile, myText);
		address = myText;
		getline(MyReadFile, myText);
		project_id = stoi(myText);

		temp.addAtEnd(name, id,phone, address,project_id);
	}

	MyReadFile.close();
	return temp;
}

LinkedList Activity::loadPrjDatabase() {
	string myText;
	string name;
	string description; 
	int client_id,id; 
	string money_earned; 
	string deadline;
	string complete_date;
	ifstream MyReadFile("Project.txt");
	LinkedList temp;
	getline(MyReadFile, myText);
	while (!MyReadFile.eof()) {
		getline(MyReadFile, myText);
		name = myText;
		getline(MyReadFile, myText);
		id = stoi(myText);
		getline(MyReadFile, myText);
		description = myText;
		getline(MyReadFile, myText);
		client_id = stoi(myText);
		getline(MyReadFile, myText);
		money_earned = myText;
		getline(MyReadFile, myText);
		deadline = myText;
		getline(MyReadFile, myText);
		complete_date = myText;
		temp.addAtEnd(name, id, description, client_id, money_earned, deadline, complete_date);
	}

	MyReadFile.close();
	return temp;
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
		regex str_expr("[0-9]+|[0-9]+\.[0-9]+");
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
		while (1) {
			cout << "Enter Joining Date with format mm-dd-yy :" << endl;
			cin >> joiningDate;
			if (joiningDate.length() == 10) {
				string yy = "";
				string mm = "";
				string dd = "";
				string ds = "";
				yy += joiningDate[6];
				yy += joiningDate[7];
				yy += joiningDate[8];
				yy += joiningDate[9];
				mm += joiningDate[0];
				mm += joiningDate[1];
				dd += joiningDate[3];
				dd += joiningDate[4];
				ds += joiningDate[2];
				ds += joiningDate[5];
				int intdd = stoi(dd);
				int intyy = stoi(yy);

				if (ds == "--") {
					if (intyy >= 2019) {
						if (mm == "01" || mm == "03" || mm == "05" || mm == "07" || mm == "08" || mm == "10" || mm == "12") {
							if (intdd > 00 && intdd <= 31) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy /n";
							}
						}
						else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
							if (intdd > 00 && intdd <= 30) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else if (mm == "02") {
							if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
								if (intdd > 00 && intdd <= 29) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
								}
							}
							else if (intdd > 00 && intdd <= 28) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else {
							cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
						}
					}
					else {
						cout << "Date is Invalid. Please enter joining date after 2019. \n";
					}
				}
				else {
					cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
				}
			}
			else {
				cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
			}
		}
		string phone;
		cout << "Enter Phone Number:" << endl;
		cin >> phone;
		regex str_exprr("[0][3][0-9]+");
		while (1) {
			if (regex_match(phone, str_exprr) && phone.size() == 11) {
				break;
			}
			else {
				cout << "Invalid Input! Enter phone number again(should start with '03' and should have total 11 entries).\n";
				cin >> phone;
			}
		}
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
		regex str_exprr("[0][3][0-9]+");
		while (1) {
			if (regex_match(phone, str_exprr) && phone.size() == 11) {
				break;
			}
			else {
				cout << "Invalid Input! Enter phone number again(should start with '03' and should have total 11 entries).\n";
				cin >> phone;
			}
		}
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
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input, Enter money earned Again." << endl;
				cin >> money_earned;
			}
			if (!cin.fail())
				break;
		}
		string deadline;
		while (1) {
			cout << "Enter Deadline mm-dd-yy :" << endl;
			cin >> deadline;
			if (deadline.length() == 10) {
				string yy = "";
				string mm = "";
				string dd = "";
				string ds = "";
				yy += deadline[6];
				yy += deadline[7];
				yy += deadline[8];
				yy += deadline[9];
				mm += deadline[0];
				mm += deadline[1];
				dd += deadline[3];
				dd += deadline[4];
				ds += deadline[2];
				ds += deadline[5];
				int intdd = stoi(dd);
				int intyy = stoi(yy);

				if (ds == "--") {
					if (intyy >= 2019) {
						if (mm == "01" || mm == "03" || mm == "05" || mm == "07" || mm == "08" || mm == "10" || mm == "12") {
							if (intdd > 00 && intdd <= 31) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy /n";
							}
						}
						else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
							if (intdd > 00 && intdd <= 30) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else if (mm == "02") {
							if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
								if (intdd > 00 && intdd <= 29) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
								}
							}
							else if (intdd > 00 && intdd <= 28) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else {
							cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
						}
					}
					else {
						cout << "Date is Invalid. Please enter date after 2019. \n";
					}
				}
				else {
					cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
				}
			}
			else {
				cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
			}
		}
		string complete_date;
		while (1) {
			cout << "Enter project completion date with format mm-dd-yy :" << endl;
			cin >> complete_date;
			if (complete_date.length() == 10) {
				string yy = "";
				string mm = "";
				string dd = "";
				string ds = "";
				yy += complete_date[6];
				yy += complete_date[7];
				yy += complete_date[8];
				yy += complete_date[9];
				mm += complete_date[0];
				mm += complete_date[1];
				dd += complete_date[3];
				dd += complete_date[4];
				ds += complete_date[2];
				ds += complete_date[5];
				int intdd = stoi(dd);
				int intyy = stoi(yy);

				if (ds == "--") {
					if (intyy >= 2019) {
						if (mm == "01" || mm == "03" || mm == "05" || mm == "07" || mm == "08" || mm == "10" || mm == "12") {
							if (intdd > 00 && intdd <= 31) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy /n";
							}
						}
						else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
							if (intdd > 00 && intdd <= 30) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else if (mm == "02") {
							if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
								if (intdd > 00 && intdd <= 29) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
								}
							}
							else if (intdd > 00 && intdd <= 28) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else {
							cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
						}
					}
					else {
						cout << "Date is Invalid. Please enter complete date after 2019\n";
					}
				}
				else {
					cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
				}
			}
			else {
				cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
			}
		}
		

		setData(name, description, client_id, money_earned, deadline, complete_date);
		database.projectDatabase();
	}
}

void Activity::readOperation(string modelOption)
{
	if (modelOption == "1") {
		database = loadEmpDatabase();
		displayEmployeeDatabase();
		system("pause");
	}
	else if (modelOption == "2") {
		database = loadCliDatabase();
		showClientDatabase();
		system("pause");
	}
	else if (modelOption == "3") {
		database = loadPrjDatabase();
		displayProjectDatabase();
		system("pause");
	}
}

void Activity::updateOperation(string modelOption)
{
	if (modelOption == "1") {
		int id;
		cout << "Enter the ID to update:" << endl;
		cin >> id;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input, Enter ID again." << endl;
				cin >>id;
			}
			if (!cin.fail())
				break;
		}
		cout << "Update Employee Details" << endl;
		cout << "Enter Name:" << endl;
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
		regex str_expr("[0-9]+|[0-9]+\.[0-9]+");
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
			while (1) {
				cout << "Enter Joining Date with format mm-dd-yy :" << endl;
				cin >> joiningDate;
				if (joiningDate.length() == 10) {
					string yy = "";
					string mm = "";
					string dd = "";
					string ds = "";
					yy += joiningDate[6];
					yy += joiningDate[7];
					yy += joiningDate[8];
					yy += joiningDate[9];
					mm += joiningDate[0];
					mm += joiningDate[1];
					dd += joiningDate[3];
					dd += joiningDate[4];
					ds += joiningDate[2];
					ds += joiningDate[5];
					int intdd = stoi(dd);
					int intyy = stoi(yy);

					if (ds == "--") {
						if (intyy >= 2019) {
							if (mm == "01" || mm == "03" || mm == "05" || mm == "07" || mm == "08" || mm == "10" || mm == "12") {
								if (intdd > 00 && intdd <= 31) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yy /n";
								}
							}
							else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
								if (intdd > 00 && intdd <= 30) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
								}
							}
							else if (mm == "02") {
								if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
									if (intdd > 00 && intdd <= 29) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
									}
								}
								else if (intdd > 00 && intdd <= 28) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
								}
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else {
							cout << "Date is Invalid. Please enter joining date after 2019. \n";
						}
					}
					else {
						cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
					}
				}
				else {
					cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
				}
			}
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
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input, Enter ID Again." << endl;
				cin >> id;
			}
			if (!cin.fail())
				break;
		}
		cout << "Enter Name:" << endl;
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
		string phone;
		cout << "Enter Phone:" << endl;
		cin >> phone;
		regex str_exprr("[0][3][0-9]+");
		while (1) {
			if (regex_match(phone, str_exprr) && phone.size() == 11) {
				break;
			}
			else {
				cout << "Invalid Input! Enter phone number again(should start with '03' and should have total 11 entries).\n";
				cin >> phone;
			}
		}
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
				cout << "You have entered wrong input, Enter Project_ID Again." << endl;
				cin >> project_id;
			}
			if (!cin.fail())
				break;
		}
		updateClientData(name, id, phone, address, project_id);
	}
	else if (modelOption == "3") {
		system("CLS");
		cout << "Update Project Details" << endl;
		int id;
		cout << "Enter Project_ID to update:" << endl;
		cin >> id;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input, enter ID Again." << endl;
				cin >> id;
			}
			if (!cin.fail())
				break;
		}
		string name;
		cout << "Enter Name:" << endl;
		cin >> name;
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
		cin >> description;
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
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "You have entered wrong input, Enter money earned Again." << endl;
				cin >> money_earned;
			}
			if (!cin.fail())
				break;
		}
		string deadline;
		while (1) {
			cout << "Enter Deadline mm-dd-yy :" << endl;
			cin >> deadline;
			if (deadline.length() == 10) {
				string yy = "";
				string mm = "";
				string dd = "";
				string ds = "";
				yy += deadline[6];
				yy += deadline[7];
				yy += deadline[8];
				yy += deadline[9];
				mm += deadline[0];
				mm += deadline[1];
				dd += deadline[3];
				dd += deadline[4];
				ds += deadline[2];
				ds += deadline[5];
				int intdd = stoi(dd);
				int intyy = stoi(yy);

				if (ds == "--") {
					if (intyy >= 2019) {
						if (mm == "01" || mm == "03" || mm == "05" || mm == "07" || mm == "08" || mm == "10" || mm == "12") {
							if (intdd > 00 && intdd <= 31) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy /n";
							}
						}
						else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
							if (intdd > 00 && intdd <= 30) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else if (mm == "02") {
							if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
								if (intdd > 00 && intdd <= 29) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
								}
							}
							else if (intdd > 00 && intdd <= 28) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else {
							cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
						}
					}
					else {
						cout << "Date is Invalid. Please enter date after 2019. \n";
					}
				}
				else {
					cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
				}
			}
			else {
				cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
			}
		}
		string complete_date;
		while (1) {
			cout << "Enter Project completion date with format mm-dd-yy :" << endl;
			cin >> complete_date;
			if (complete_date.length() == 10) {
				string yy = "";
				string mm = "";
				string dd = "";
				string ds = "";
				yy += complete_date[6];
				yy += complete_date[7];
				yy += complete_date[8];
				yy += complete_date[9];
				mm += complete_date[0];
				mm += complete_date[1];
				dd += complete_date[3];
				dd += complete_date[4];
				ds += complete_date[2];
				ds += complete_date[5];
				int intdd = stoi(dd);
				int intyy = stoi(yy);

				if (ds == "--") {
					if (intyy >= 2019) {
						if (mm == "01" || mm == "03" || mm == "05" || mm == "07" || mm == "08" || mm == "10" || mm == "12") {
							if (intdd > 00 && intdd <= 31) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy /n";
							}
						}
						else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
							if (intdd > 00 && intdd <= 30) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else if (mm == "02") {
							if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
								if (intdd > 00 && intdd <= 29) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
								}
							}
							else if (intdd > 00 && intdd <= 28) {
								break;
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
							}
						}
						else {
							cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
						}
					}
					else {
						cout << "Date is Invalid. Please enter complete date after 2019\n";
					}
				}
				else {
					cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
				}
			}
			else {
				cout << "Date is Invalid. Please follow the format of mm-dd-yy \n";
			}
		}
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




