#include "Activity.h"

void Activity::setData(string name, int id, double salary, string project, string joiningDate, string phone, string address)
{
	emp.setName(name);
	emp.setId(id);
	emp.setSalary(salary);
	emp.setProject(project);
	emp.setJoiningDate(joiningDate);
	emp.setPhone(phone);
	emp.setAddress(address);
	enterToEmployeeDatabase();
}


void Activity::setData(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date) {
	prj.setname(name);
	prj.setid(id);
	prj.setdescription(description);
	prj.setclient_id(client_id);
	prj.setmoney_earned(money_earned);
	prj.setdeadline(deadline);
	prj.setcomplete_date(complete_date);
}


void Activity::setData(string name, int id, string phone, string address, int project_id)
{
	cli.setName(name);
	cli.setId(id);
	cli.setPhone(phone);
	cli.setAddress(address);
	cli.setProject_Id(project_id);
}


void Activity::enterToEmployeeDatabase()
{
	database.addAtEnd(emp.getName(), emp.getId(), emp.getSalary(), emp.getProject(), emp.getJoiningDate(), emp.getPhone(), emp.getAddress());
}


void Activity::deleteEndProjectDatabase() {
	database.deleteAtEndPrj();
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


void Activity::displayProjectDatabase(){
	display.showProjectDatabase(database);
}

void Activity::displayEmployeeDatabase()
{
	display.showEmployee(database);
}

void Activity::updateEmployeeDatabase(string name, int id, double salary, string project, string joiningDate, string phone, string address)
{
	database.updateEmployee(name, id, salary, project, joiningDate, phone, address);
}
void Activity::enterToCliDatabase()
{
	database.addAtEnd(cli.getName(), cli.getId(), cli.getPhone(), cli.getAddress(), cli.getProject_Id());
}

void Activity::updateCliDataById() {
	database.updateCliList();
}

void Activity::deleteCliDataById() {
	database.deleteById();
}

void Activity::deleteEmployee(int id)
{
	database.deleteByEmployeeId(id);
}


