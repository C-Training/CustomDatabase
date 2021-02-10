#pragma once
#include <iostream>
using namespace std;

class Client {

    string name;
    int id = 0;
    string phone;
    string address;
    string project_id;

public:

    void setName(string name);
    void setId(int id);
    void setPhone(string phone);
    void setAddress(string address);
    void setProject_Id(string id);

    string getName();
    int getId();
    string getPhone();
    string getAddress();
    string getProject_Id();

};
