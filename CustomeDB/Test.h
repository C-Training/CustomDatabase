#pragma once
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include <string>

class Test {
public:
    Node* t1 = NULL;
    int testNumber = 0;
    //void test();

    Test();

    bool check(Node* obj);

    void testaddAtEnd(int id, string name, int price);
    void testaddAtHead(int id, string name, int price);
    void testdeleteAtHead();
    void testdeleteById(int id);
    void testdisplayList();
    void testupdatePrice(int old_val, int new_val);
    void testswapNodes(Node* cur, Node* index);
    void testsortByNameAes();
    void testsortByNameDec();
    size_t testlistSize();
    void testreverseLinkedList();
};
