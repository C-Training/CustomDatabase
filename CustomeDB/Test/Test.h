#pragma once
#include "Node.h"
#include <iostream>
#include "LinkedList.h"

class Test {
public:
    Node* t1 = NULL;
    Test();

    bool check(Node* obj);

    void testaddAtEnd(int id, string name, int price);
};
