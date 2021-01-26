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

