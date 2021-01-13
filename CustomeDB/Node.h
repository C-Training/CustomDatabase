#pragma once
#include <string>
#include "item.h"

using namespace std;

class Node {
public:
    Node(int id, string name, int price);
    Item data;
    Node* next;
};

