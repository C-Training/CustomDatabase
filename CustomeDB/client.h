#pragma once
#include <iostream>
using namespace std;

class Client {

    string name;
    int cl_id;
    string phone;
    string address;
    int project_id;

public:

    void setname(string name);
    void setcl_id(int cl_id);
    void setphone(string phone);
    void setaddress(string address);
    void setproject_id(int id);

    string getname();
    int getcl_id();
    string getphone();
    string getaddress();
    int getproject_id();

};