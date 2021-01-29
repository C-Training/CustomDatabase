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
}

void Activity::setData(string name, int id, string phone, string address, int project_id)
{
	cli.setName(name);
	cli.setId(id);
	cli.setPhone(phone);
	cli.setAddress(address);
	cli.setProject_Id(project_id);
}

void Activity::enterToDatabase()
{
	database.addAtEnd(emp.getName(), emp.getId(), emp.getSalary(), emp.getProject(), emp.getJoiningDate(), emp.getPhone(), emp.getAddress());
}

void Activity::enterToCliDatabase()
{
	database.addAtEnd(cli.getName(), cli.getId(), cli.getPhone(), cli.getAddress(), cli.getProject_Id());
}

void Activity::updateClientData(string name, int id, string phone, string address, int project_id) {
	database.updateClient(name, id, phone,  address,  project_id);
}

void Activity::deleteCliDataById() {
	database.deleteById();
}

void Activity::displayCliList() {
	database.displayCliList();
}
