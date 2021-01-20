#include "client.h"

void client::setname(string name) {

    this->name = name;
}

void client::setid(int id) {

    this->id = id;
}

void client::setphone(long phone) {

    this->phone = phone;
}

void client::setaddress(string address) {

    this->address = address;
}

void client::setproject_id(int project_id) {

    this->project_id = project_id;
}

string client::getname() {

    return name;
}

int client::getid() {

    return id;
}

long client::getphone() {

    return phone;
}

string client::getaddress() {

    return address;
}

int client::getproject_id() {

    return project_id;
}