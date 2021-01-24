#include "Acitivity.h"

	void Acitivity::setdata(string name, int id, string phone, string address, int project_id) {
		cli.setname(name);
		cli.setid(id);
		cli.setphone(phone);
		cli.setaddress(address);
		cli.setproject_id(project_id);
	}

	void Acitivity::entertodatabase() {
		database.addAtcliEnd(cli.getname(), cli.getid(), cli.getphone(), cli.getaddress(), cli.getproject_id());
	}

	void Acitivity::displaydatabase() {
		database.displayclilist();
	}