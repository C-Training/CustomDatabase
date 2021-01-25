#include "Acitivity.h"

	void Acitivity::setdata(string name, int cl_id, string phone, string address, int project_id) {
		cli.setname(name);
		cli.setcl_id(cl_id);
		cli.setphone(phone);
		cli.setaddress(address);
		cli.setproject_id(project_id);
	}

	void Acitivity::entertodatabase() {
		database.addAtEnd(cli.getname(), cli.getcl_id(), cli.getphone(), cli.getaddress(), cli.getproject_id());
	}

