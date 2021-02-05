#include "client.h"

void Client::setName(string name) {

    this->name = name;
}

void Client::setId(int id) {

    this->id = id;
}

void Client::setPhone(string phone) {

    this->phone = phone;
}

void Client::setAddress(string address) {

    this->address = address;
}

void Client::setProject_Id(int project_id) {

    this->project_id = project_id;
}

string Client::getName() {

    return name;
}

int Client::getId() {

    return id;
}

string Client::getPhone() {

    return phone;
}

string Client::getAddress() {

    return address;
}

int Client::getProject_Id() {

    return project_id;
}