#include "Activity.h"


void Activity::setdata(string name, int cl_id, string phone, string address, int project_id) {
	cli.setname(name);
	cli.setcl_id(cl_id);
	cli.setphone(phone);
	cli.setaddress(address);
	cli.setproject_id(project_id);
}

void Activity::entertoclidatabase() {
	database.addAtHead(cli.getname(), cli.getcl_id(), cli.getphone(), cli.getaddress(), cli.getproject_id());
}

void Activity::displaydatabase()
{
	database.displaycliList();
}


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

void Activity::enterToDatabase()
{
	database.addAtEnd(emp.getName(), emp.getId(), emp.getSalary(), emp.getProject(), emp.getJoiningDate(), emp.getPhone(), emp.getAddress());
}

void Activity::displayDatabase()
{
	database.displayList();
}

