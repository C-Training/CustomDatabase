#pragma once
#include <string>
using namespace std;


class Item {

    string name;
    int price;
    int id;
public:
    void setName(string name);
    string getName();

    void setId(int id);
    int getId();

    void setPrice(int price);
    int getPrice();
};

