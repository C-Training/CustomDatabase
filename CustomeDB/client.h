#pragma once
#include <iostream>
using namespace std;

class client {

    string name;
    int id;
    string phone;
    string address;
    int project_id;

public:

    void setname(string name);
    void setid(int id);
    void setphone(string phone);
    void setaddress(string address);
    void setproject_id(int id);

    string getname();
    int getid();
    string getphone();
    string getaddress();
    int getproject_id();

};