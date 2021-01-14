#include "node.h"

Node::Node(int price, int ID, string name)
{
    this->data.ID = ID;
    this->data.name = name;
    this->data.price = price;
}
