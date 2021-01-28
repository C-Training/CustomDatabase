#pragma once
#include <iostream>
using namespace std;

class Client {

    string name;
    int id;
    string phone;
    string address;
    int project_id;

public:

    void setName(string name);
    void setId(int id);
    void setPhone(string phone);
    void setAddress(string address);
    void setProject_Id(int id);

    string getName();
    int getId();
    string getPhone();
    string getAddress();
    int getProject_Id();

};