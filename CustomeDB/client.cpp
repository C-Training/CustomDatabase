#include "client.h"

void Client::setname(string name) {

    this->name = name;
}

void Client::setid(int id) {

    this->id = id;
}

void Client::setphone(string phone) {

    this->phone = phone;
}

void Client::setaddress(string address) {

    this->address = address;
}

void Client::setproject_id(int project_id) {

    this->project_id = project_id;
}

string Client::getname() {

    return name;
}

int Client::getid() {

    return id;
}

string Client::getphone() {

    return phone;
}

string Client::getaddress() {

    return address;
}

int Client::getproject_id() {

    return project_id;
}