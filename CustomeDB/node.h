#pragma once;
#include "data.h"
#include <string>;
using namespace std;

struct Node {
public:
    Node(int price,int ID,string name);
    item data;
    Node* next;
};

struct Node* head = NULL;
