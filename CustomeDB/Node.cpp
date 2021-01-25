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
	client.setname("");
	client.setcl_id(0);
	client.setphone("");
	client.setaddress("");
	client.setproject_id(0);
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

Node::Node(string name, int cl_id, string phone, string address, int project_id) {
	client.setname(name);
	client.setcl_id(cl_id);
	client.setphone(phone);
	client.setaddress(address);
	client.setproject_id(project_id);
}

Employee Node::getEmployee()
{
	return emp;
}

Client Node::getClient()
{
	return client;
}

