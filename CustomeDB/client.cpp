#include "client.h"

void Client::setName(string name) {

    this->name = name;
}

int Client::counter = 1;

void Client::setId(int id) {

    this->id = counter++;
}

void Client::setPhone(string phone) {

    this->phone = phone;
}

void Client::setAddress(string address) {

    this->address = address;
}

void Client::setProject_Id(string project_id) {

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

string Client::getProject_Id() {

    return project_id;
}

