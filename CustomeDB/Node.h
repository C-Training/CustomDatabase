#pragma once
#include "data.h"
#include <string>
using namespace std;

struct Node {
public:
    Node(int price, int ID, string name);
    Node* next;

    int getid();
    string getname();
    int getprice();

    void setid(int id);
    void setname(string name);
    void setprice(int price);

private:
    item data;
};