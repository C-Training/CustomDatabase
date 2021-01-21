#include "Node.h"

Node::Node()
{
	emp.setName("");
	emp.setId(0);
	emp.setSalary(0.0);
	emp.setProject("");
	emp.setJoiningDate("");
	emp.setPhone("");
	emp.setAddress("");
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

Employee Node::getEmployee()
{
	return emp;
}


