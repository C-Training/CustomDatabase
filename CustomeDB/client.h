#pragma once
#include <iostream>
using namespace std;

class client {

    string name;
    int id;
    long phone;
    string address;
    int project_id;

public:

    string setname(string name);
    int setid(int id);
    int setphone(long phone);
    string setaddress(string address);
    int setproject_id(int id);

    string getname();
    int getid();
    int getphone();
    string getaddress();
    int getproject_id();

}