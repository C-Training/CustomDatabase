#pragma once
#include "node.h"
#include <iostream>
#include<fstream>
using namespace std;

class linkedlist {
    Node* head = NULL;

public:
    Node* getHead();
    void insert(int prc, string nme, int id);

    void update_price(int id, int new_price);

    void print();

    void display();

    void reverse();

    void sort();

    void size();

    void deletehead();
};