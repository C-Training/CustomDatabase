#include "Activity.h"

Activity::Activity()
{
	database.emphead = loadEmpDatabase();
	database.clienthead = loadCliDatabase();
	database.prjhead = loadPrjDatabase();
}

Activity::~Activity()
{
	database.employeeDatabase();
	database.clientDatabase();
	database.projectDatabase();
}

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

void Activity::setData(string name, string phone, string address, string project_id)
{
	cli.setName(name);
	cli.setId(cli.getId()+1);
	cli.setPhone(phone);
	cli.setAddress(address);
	cli.setProject_Id(project_id);
	enterToCliDatabase();
}

void Activity::setDataProject(string name, string description, string money_earned, string deadline, string complete_date, string client_id) {
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

bool Activity::is_empty(ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}

void Activity::updateByIdPrj(int id, string name, string description, string money_earned, string deadline, string complete_date, string client_id) {
	database.updateByIdPrj(id, name,description, money_earned,deadline,complete_date, client_id);
}

void Activity::updateClientData(string name, int id, string phone, string address, string project_id) {
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



Node* Activity::loadEmpDatabase() {
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
	if (is_empty(MyReadFile)) {
		
	}
	else {
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
	}
	
	MyReadFile.close();
	return temp.emphead;
}

Node* Activity::loadCliDatabase() {
	string myText;
	string name;
	int id;
	string project_id;
	string phone;
	string address;
	ifstream MyReadFile("Client.txt");
	LinkedList temp;
	if (is_empty(MyReadFile)) {
		
	}
	else {
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
			getline(MyReadFile, myText); //MyReadFile >> myText;
			project_id = myText;

			temp.addAtEnd(name, id, phone, address, project_id);
		}
	}
	
	MyReadFile.close();
	return temp.clienthead;
}

Node* Activity::loadPrjDatabase() {
	string myText;
	string name;
	string description; 
	string client_id;
	int id;
	string money_earned; 
	string deadline;
	string complete_date;
	ifstream MyReadFile("Project.txt");
	LinkedList temp;
	if (is_empty(MyReadFile)) {
		
	}
	else {
		getline(MyReadFile, myText);
		while (!MyReadFile.eof()) {
			getline(MyReadFile, myText);
			name = myText;
			getline(MyReadFile, myText);
			id = stoi(myText);
			getline(MyReadFile, myText);
			description = myText;
			getline(MyReadFile, myText);
			client_id = myText;
			getline(MyReadFile, myText);
			money_earned = myText;
			getline(MyReadFile, myText);
			deadline = myText;
			getline(MyReadFile, myText);
			complete_date = myText;
			temp.addAtEnd(id, name, description, money_earned, deadline, complete_date, client_id);
		}
	}

	MyReadFile.close();
	return temp.prjhead;
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
	else if (crudOption == "5") {
		display.showHome();
		system("CLS");
	}
	else if (crudOption == "6") {
		exit(1);
	}
	else {
		cout << "Your CRUD option is incorrect" << endl;
	}
}

void Activity::createOperation(string modelOption)
{
	if (modelOption == "1") {
		cout << "Enter Employee Details" << endl;
		cout << "Enter 0 if you want to return to Employee CRUD Menu" << endl;
		cout << "Enter Name:\n";
		cin.ignore();
		string name = "";
		getline(cin, name);
		while (1)
		{
			bool isEqual = false;
			if (name == "0") { string crudOption; display.showCRUD("Employee"); cin >> crudOption; crudOperation("1", crudOption); break; system("CLS");
			};
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
			if (salary == "0") {
				string crudOption; display.showCRUD("Employee"); cin >> crudOption; crudOperation("1", crudOption); break; system("CLS");
			};
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
		cin.ignore();
		getline(cin, project);
		while (1) {
			if (project == "0") {
				string crudOption; display.showCRUD("Employee"); cin >> crudOption; crudOperation("1", crudOption); break; system("CLS");
			};
			break;
		}
		string joiningDate;
		regex str_date("[0-9][0-9]-[0-9][0-9]-[2-9][0-9][0-9][0-9]");
		while (1) {
			cout << "Enter Joining Date with format mm-dd-yyyy :" << endl;
			cin >> joiningDate;
			if (joiningDate == "0") {
				string crudOption; display.showCRUD("Employee"); cin >> crudOption; crudOperation("1", crudOption); break; system("CLS");
			};

			if (regex_match(joiningDate, str_date)) {

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
					int intmm = stoi(mm);

					if (ds == "--") {
						if (intyy >= 2019) {
							if (mm == "01" || mm == "03" || mm == "05" || mm == "07" || mm == "08" || mm == "10" || mm == "12") {
								if (intdd > 00 && intdd <= 31) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy /n";
								}
							}
							else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
								if (intdd > 00 && intdd <= 30) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
								}
							}
							else if (mm == "02") {
								if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
									if (intdd > 00 && intdd <= 29) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
									}
								}
								else if (intdd > 00 && intdd <= 28) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
								}
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
							}
						}
						else {
							cout << "Date is Invalid. Please enter joining date after 2019. \n";
						}
					}
					else {
						cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
					}
				}
			}

			else {
				cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
			}
		}
		string phone;
		cout << "Enter Phone Number:" << endl;
		cin >> phone;
		regex str_exprr("[0][3][0-9]+");
		while (1) {
			if (phone == "0") {
				string crudOption; display.showCRUD("Employee"); cin >> crudOption; crudOperation("1", crudOption); break; system("CLS");
			};
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
		cin.ignore();
		getline(cin, address);
		while (1) {
			if (address == "0") {
				string crudOption; display.showCRUD("Employee"); cin >> crudOption; crudOperation("1", crudOption); break; system("CLS");
			};
			break;
		}

		setData(name, salary, project, joiningDate, phone, address);
	}
	else if (modelOption == "2") {
		cout << "Enter Client Details" << endl;
		cout << "Enter 0 if you want to return to Client CRUD Menu" << endl;
		string name = "";
		cout << "Enter Name:" << endl;
		cin.ignore();
		getline(cin, name);
		while (1)
		{
			bool isEqual = false;
			if (name == "0") {
				string crudOption; display.showCRUD("Client"); cin >> crudOption; crudOperation("2", crudOption); break; 
			};	for (int i = 48; i <= 57; i++) {
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
			if (phone == "0") {
				string crudOption; display.showCRUD("Client"); cin >> crudOption; crudOperation("2", crudOption); break;
			};
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
		cin.ignore();
		getline(cin, address);
		while (1) {
			if (address == "0") {
				string crudOption; display.showCRUD("Client"); cin >> crudOption; crudOperation("2", crudOption); break;
			};
			break;
		}
		string project_id;
		cout << "Enter Project_ID:" << endl;
		regex str_expr("[0-9]+");
		while (1) {
			getline(cin, project_id);
			bool isEqual = false;
			for (int i = 32; i <= 126; i++) {
				if (i >= 48 && i <= 57)
					continue;
				for (int j = 0; j < project_id.size(); j++) {
					if (i == project_id[j]) {
						isEqual = true;
						break;
					}
				}
				if (isEqual)
					break;
			}
			if (isEqual) {
				cout << "You can only enter digits NIGGAW!\n";
				continue;
			}
			else if (regex_match(project_id, str_expr) && project_id.size() <= 6) {
				cout << "valid input, GOOD JOB! gachiBASS\n";
				break;
			}
			else {
				cout << "Invalid Input! Enter Project ID again(ID cannot be greater than 6 digits).\n";
			}
		}
		setData(name, phone, address, project_id);
		
	}
	else if (modelOption == "3") {
		cout << "Enter Project Details" << endl;
		cout << "Enter 0 if you want to return to Project CRUD Menu" << endl;
		string name = "";
		cout << "Enter Name:" << endl;
		cin.ignore();
		getline(cin, name);
		while (1)
		{
			bool isEqual = false;
			if (name == "0") {
				string crudOption; display.showCRUD("Project"); cin >> crudOption; crudOperation("3", crudOption); break; 
			};
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
		cin.ignore();
		getline(cin, description);
		while (1) {
			if (description == "0") {
				string crudOption; display.showCRUD("Project"); cin >> crudOption; crudOperation("3", crudOption); break;
			};
			break;
		}
		string client_id;
		cout << "Enter Client_ID:" << endl;
		regex str_expr("[0-9]+");
		while (1) {
			getline(cin, client_id);
			bool isEqual = false;
			for (int i = 32; i <= 126; i++) {
				if (i >= 48 && i <= 57)
					continue;
				for (int j = 0; j < client_id.size(); j++) {
					if (i == client_id[j]) {
						isEqual = true;
						break;
					}
				}
				if (isEqual)
					break;
			}
			if (isEqual) {
				continue;
			}
			else if (regex_match(client_id, str_expr) && client_id.size() <= 6) {
				break;
			}
			else {
				cout << "Invalid Input! Enter Client ID again(ID cannot be greater than 6 digits).\n";
			}
		}
		string money_earned;
		regex str_exprrr("[0-9]+|[0-9]+\.[0-9]+");
		
		cout << "Enter money earned:" << endl;
		
		while (1) {

			cin >> money_earned;

			if (regex_match(money_earned, str_exprrr)) {
				break;
			}
			else {
				cout << "Kindly enter correct value \n";
			}
		}
		string deadline;
		regex str_date("[0-9][0-9]-[0-9][0-9]-[2-9][0-9][0-9][0-9]");
		while (1) {
			cout << "Enter Deadline date with format mm-dd-yyyy :" << endl;
			cin >> deadline;			
			if (deadline == "0") {
				string crudOption; display.showCRUD("Project"); cin >> crudOption; crudOperation("3", crudOption); break;
			}
			if (regex_match(deadline, str_date)) {

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
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy /n";
								}
							}
							else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
								if (intdd > 00 && intdd <= 30) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
								}
							}
							else if (mm == "02") {
								if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
									if (intdd > 00 && intdd <= 29) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
									}
								}
								else if (intdd > 00 && intdd <= 28) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
								}
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
							}
						}
						else {
							cout << "Date is Invalid. Please enter date after 2019. \n";
						}
					}
					else {
						cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
					}
				}
			}
			 
			else {
				cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
			}
		}

		string complete_date;
		regex strr_date("[0-9][0-9]-[0-9][0-9]-[2-9][0-9][0-9][0-9]");
		while (1) {
			cout << "Enter project completion date with format mm-dd-yyyy :" << endl;
			cin >> complete_date;
			if (complete_date == "0") {
				string crudOption; display.showCRUD("Project"); cin >> crudOption; crudOperation("3", crudOption); break;
			}

			if (regex_match(deadline, strr_date)) {

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
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy /n";
								}
							}
							else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
								if (intdd > 00 && intdd <= 30) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
								}
							}
							else if (mm == "02") {
								if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
									if (intdd > 00 && intdd <= 29) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
									}
								}
								else if (intdd > 00 && intdd <= 28) {
									break;
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
								}
							}
							else {
								cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
							}
						}
						else {
							cout << "Date is Invalid. Please enter complete date after 2019\n";
						}
					}
					else {
						cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
					}
				}
			}
			else {
				cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
			}
		}
		
		setData(name, description, money_earned, deadline, complete_date, client_id);
	}
}

void Activity::readOperation(string modelOption)
{
	if (modelOption == "1") {
		if (database.employeeListSize() != 0) {
			displayEmployeeDatabase();
		}
		else {
			cout << "Employee database is empty.\n";
		}
		system("pause");
	}
	else if (modelOption == "2") {
		if (database.ClilistSize() != 0) {
			showClientDatabase();
		}
		else {
			cout << "Client database is empty.\n";
		}
		system("pause");
	}
	else if (modelOption == "3") {
		if (database.listSizeProj() != 0) {
			displayProjectDatabase();
		}
		else {
			cout << "Project database is empty.\n";
		}
		system("pause");
	}
}

bool Activity::checkEmpId(int id) {
	Node* temp = database.getempHead();
	bool found = false;
	while (temp != NULL) {
		if ((temp->getEmployee().getId()) == id) {
			found = true;
			break;
		}
		temp = temp->next;
	}
	if (found == true) { return true; }
	else{
		return false;
}
}

bool Activity::checkCliId(int id) {
	Node* temp = database.getclientHead();
	bool found = false;
	while (temp != NULL) {
		if ((temp->getClient().getId()) == id) {
			found = true;
			break;
		}
		temp = temp->next;
		}
	if (found == true) {
		return true;
	}
	return false;
}

bool Activity::checkPrjId(int id) {
	Node* temp = database.getProjectHead();
	bool found = false;
	while (temp != NULL) {
		if ((temp->getProject().getid()) == id) {
			found = true;
			break;
		}
		temp = temp->next;
	}
	if (found == true) {
		return true;
	}
	return false;

}

void Activity::updateOperation(string modelOption)
{
	if (modelOption == "1") {
		int id;
		string id_check;
		cout << "Enter the ID to update:" << endl;

		regex str_expr("[0-9]+");
		while (1) {
			cin >> id_check;
			if (regex_match(id_check, str_expr)) {
				id = stoi(id_check);
				break;
			}
			else {
				cout << "Invalid Input, Enter again.\n";
			}
		}
		if (checkEmpId(id) == false) { cout << "The Employee of that ID is either classfied or not present" << endl; }
		else if (checkEmpId(id) == true) {
			cout << "Update Employee Details" << endl;
			string name;
			cout << "Enter Name:" << endl;
			cin.ignore();
			getline(cin, name);
			string salary;
			cout << "Enter Salary:" << endl;
			cin >> salary;
			regex str_expr("[0-9]+|[0-9]+\.[0-9]+");
			while (1) {
				if (salary == "0") {
					string crudOption; display.showCRUD("Employee"); cin >> crudOption; crudOperation("1", crudOption); break; system("CLS");
				};
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
			cin.ignore();
			getline(cin, project);
			string joiningDate;
			regex str_date("[0-9][0-9]-[0-9][0-9]-[2-9][0-9][0-9][0-9]");
			while (1) {
				cout << "Enter Joining Date with format mm-dd-yyyy :" << endl;
				cin >> joiningDate;

				if (regex_match(joiningDate, str_date)) {

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
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy /n";
									}
								}
								else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
									if (intdd > 00 && intdd <= 30) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
									}
								}
								else if (mm == "02") {
									if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
										if (intdd > 00 && intdd <= 29) {
											break;
										}
										else {
											cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
										}
									}
									else if (intdd > 00 && intdd <= 28) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
									}
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
								}
							}
							else {
								cout << "Date is Invalid. Please enter joining date after 2019. \n";
							}
						}
						else {
							cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
						}
					}
				}
				else {
					cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
				}
			}
			string phone;
			cout << "Enter Phone Number:" << endl;
			cin >> phone;
			regex str_exprr("[0][3][0-9]+");
			while (1) {
				if (phone == "0") {
					string crudOption; display.showCRUD("Employee"); cin >> crudOption; crudOperation("1", crudOption); break; system("CLS");
				};
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
			cin.ignore();
			getline(cin, address);
			updateDatabase(name, id, salary, project, joiningDate, phone, address);
		}
	}
	else if (modelOption == "2") {
		cout << "Update Client Details" << endl;
		int id;
		string id_check;
		cout << "Enter the ID to update:" << endl;

		regex str_expr("[0-9]+");
		while (1) {
			cin >> id_check;
			if (regex_match(id_check, str_expr)) {
				id = stoi(id_check);
				break;
			}
			else {
				cout << "Invalid Input, Enter again.\n";
			}
		}
		if (checkCliId(id) == false) {
			cout << "Id not present" << endl;
		}
		else if (checkCliId(id) == true) {
			string name;
			cout << "Enter Name:" << endl;
			cin.ignore();
			getline(cin, name);
			string phone;
			cout << "Enter Phone:" << endl;
			cin >> phone;
			regex str_exprr("[0][3][0-9]+");
			while (1) {
				if (phone == "0") {
					string crudOption; display.showCRUD("Client"); cin >> crudOption; crudOperation("2", crudOption); break;
				};
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
			cin.ignore();
			getline(cin, address);
			string project_id;
			cout << "Enter Project_ID:" << endl;
			regex str_expr("[0-9]+");
			while (1) {
				getline(cin, project_id);
				bool isEqual = false;
				for (int i = 32; i <= 126; i++) {
					if (i >= 48 && i <= 57)
						continue;
					for (int j = 0; j < project_id.size(); j++) {
						if (i == project_id[j]) {
							isEqual = true;
							break;
						}
					}
					if (isEqual)
						break;
				}
				if (isEqual) {
					cout << "You can only enter digits NIGGAW!\n";
					continue;
				}
				else if (regex_match(project_id, str_expr) && project_id.size() <= 6) {
					cout << "valid input, GOOD JOB! gachiBASS\n";
					break;
				}
				else {
					cout << "Invalid Input! Enter Project ID again(ID cannot be greater than 6 digits).\n";
				}
			}
			updateClientData(name, id, phone, address, project_id);
		}
	}
	else if (modelOption == "3") {
		system("CLS");
		cout << "Update Project Details" << endl;
		int id;
		string id_check;
		cout << "Enter the ID to update:" << endl;

		regex str_expr("[0-9]+");
		while (1) {
			cin >> id_check;
			if (regex_match(id_check, str_expr)) {
				id = stoi(id_check);
				break;
			}
			else {
				cout << "Invalid Input, Enter again.\n";
			}
		}
		if (checkPrjId(id) == false) { cout << "We are sorry that your id is not present" << endl; }
		else if (checkPrjId(id) == true) {
			string name;
			cout << "Enter Name:" << endl;
			cin.ignore();
			getline(cin, name);
			string description;
			cout << "Enter description" << endl;
			cin.ignore();
			getline(cin, description);
			string client_id;
			cout << "Enter Client_ID:" << endl;
			regex str_expr("[0-9]+");
			while (1) {
				getline(cin, client_id);
				bool isEqual = false;
				for (int i = 32; i <= 126; i++) {
					if (i >= 48 && i <= 57)
						continue;
					for (int j = 0; j < client_id.size(); j++) {
						if (i == client_id[j]) {
							isEqual = true;
							break;
						}
					}
					if (isEqual)
						break;
				}
				if (isEqual) {

					continue;
				}
				else if (regex_match(client_id, str_expr) && client_id.size() <= 6) {

					break;
				}
				else {
					cout << "Invalid Input! Enter Client ID again(ID cannot be greater than 6 digits).\n";
				}
			}
			string money_earned;
			regex str_exprrr("[0-9]+|[0-9]+\.[0-9]+");

			cout << "Enter money earned:" << endl;

			while (1) {

				cin >> money_earned;

				if (regex_match(money_earned, str_exprrr)) {
					break;
				}
				else {
					cout << "Kindly enter correct value \n";
				}
			}
			string deadline;
			regex str_date("[0-9][0-9]-[0-9][0-9]-[2-9][0-9][0-9][0-9]");
			while (1) {
				cout << "Enter Deadline with format mm-dd-yyyy :" << endl;
				cin >> deadline;


				if (regex_match(deadline, str_date)) {

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
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy /n";
									}
								}
								else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
									if (intdd > 00 && intdd <= 30) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
									}
								}
								else if (mm == "02") {
									if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
										if (intdd > 00 && intdd <= 29) {
											break;
										}
										else {
											cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
										}
									}
									else if (intdd > 00 && intdd <= 28) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
									}
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
								}
							}
							else {
								cout << "Date is Invalid. Please enter date after 2019. \n";
							}
						}
						else {
							cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
						}
					}
				}

				else {
					cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
				}
			}
			string complete_date;
			regex strr_date("[0-9][0-9]-[0-9][0-9]-[2-9][0-9][0-9][0-9]");
			while (1) {
				cout << "Enter project completion date with format mm-dd-yyyy :" << endl;
				cin >> complete_date;

				if (regex_match(deadline, strr_date)) {


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
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy /n";
									}
								}
								else if (mm == "04" || mm == "06" || mm == "09" || mm == "11") {
									if (intdd > 00 && intdd <= 30) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
									}
								}
								else if (mm == "02") {
									if ((intyy % 400 == 0 || (intyy % 100 != 0 && intyy % 4 == 0))) {
										if (intdd > 00 && intdd <= 29) {
											break;
										}
										else {
											cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
										}
									}
									else if (intdd > 00 && intdd <= 28) {
										break;
									}
									else {
										cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
									}
								}
								else {
									cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
								}
							}
							else {
								cout << "Date is Invalid. Please enter complete date after 2019\n";
							}
						}
						else {
							cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
						}
					}
				}

				else {
					cout << "Date is Invalid. Please follow the format of mm-dd-yyyy \n";
				}
			}
			updateByIdPrj(id, name, description, money_earned, deadline, complete_date, client_id);
		}
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








