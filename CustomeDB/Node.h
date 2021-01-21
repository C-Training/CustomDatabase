#pragma once
#include <string>
#include "item.h"
#include "client.h"

using namespace std;

class Node {
private:
    Client client;
public:
    Node();
    Node(string name,int id,string phone,string address,int project_id);
    Node* next;
    Client getClient();
};

