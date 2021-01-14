#pragma once
#include <string>
#include "item.h"

using namespace std;

class Node {

    Item data;
public:

    Node(int id, string name, int price);
    Node* next;
    string getName();
    int getId();
    int getPrice();
    void setName(string name);
    void setId(int id);
    void setPrice(int price);
};

