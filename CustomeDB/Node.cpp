#include "node.h"

Node::Node(int price, int ID, string name)
{
    this->data.ID = ID;
    this->data.name = name;
    this->data.price = price;
}

int Node::getid()
{
    return data.ID;
}

string Node::getname()
{
    return data.name;
}

int Node::getprice()
{
    return data.price;
}

void Node::setid(int id)
{
    this->data.ID = id;
}

void Node::setname(string name)
{
    this->data.name = name;
}

void Node::setprice(int price)
{
    this->data.price = price;
}