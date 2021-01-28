#include "Node.h"

Node::Node()
{
	cout << "Node class created" << endl;
	next = NULL;
}




Node::Node(string name, int id, double salary, string project, string joiningDate, string phone, string address)
{
	emp.setName(name);
	emp.setId(id);
	emp.setSalary(salary);
	emp.setProject(project);
	emp.setJoiningDate(joiningDate);
	emp.setPhone(phone);
	emp.setAddress(address);
}

Node::Node(string name, int id, string phone, string address, int project_id) {
	client.setname(name);
	client.setid(id);
	client.setphone(phone);
	client.setaddress(address);
	client.setproject_id(project_id);
}

Node::Node(string name, int id, string description, int client_id, string money_earned, string deadline, string complete_date) {
	prj.setname(name);
	prj.setid(id);
	prj.setdescription(description);
	prj.setclient_id(client_id);
	prj.setmoney_earned(money_earned);
	prj.setdeadline(deadline);
	prj.setcomplete_date(complete_date);
}

Employee Node::getEmployee()
{
	return emp;
}

Project Node::getProject() {
	return prj;
}

Client Node::getClient()
{
	return client;
}

