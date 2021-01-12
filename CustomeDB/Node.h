#pragma once
#include <string>
#include "item.h"

using namespace std;

class Node {
public:
    Node(int id, string name, int price) {
        this->data.id = id;
        this->data.name = name;
        this->data.price = price;
    }
    Item data;
    Node* next;
};

