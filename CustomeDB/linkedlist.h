#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include "node.h"
using namespace std;

class linkedlist {
public:
    void insert(int prc, string nme, int id);

    void update_data(int id, int new_price);

    void print(); 

    void display();

    void reverse();

    void sort();

    void size();

    void deletehead();
};