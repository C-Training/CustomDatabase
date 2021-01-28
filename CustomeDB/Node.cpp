#include "Node.h"

//Node::Node()
//{
//	emp.setName("");
//	emp.setId(0);
//	emp.setSalary(0.0);
//	emp.setProject("");
//	emp.setJoiningDate("");
//	emp.setPhone("");
//	emp.setAddress("");
//}

Node::Node() {
	client.setName("");
	client.setId(0);
	client.setPhone("");
	client.setAddress("");
	client.setProject_Id(0);
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
	client.setName(name);
	client.setId(id);
	client.setPhone(phone);
	client.setAddress(address);
	client.setProject_Id(project_id);
}

Employee Node::getEmployee()
{
	return emp;
}

Client Node::getClient()
{
	return client;
}

