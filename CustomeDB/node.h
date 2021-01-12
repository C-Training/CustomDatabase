#pragma once;
#include <string>;
using namespace std;

struct Node {
    int price;
    int ID;
    string name;
    Node* next;
};

struct Node* head = NULL;
