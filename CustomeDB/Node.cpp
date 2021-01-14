#include "Node.h"

Node::Node(int id, string name, int price) {
    this->data.id = id;
    this->data.name = name;
    this->data.price = price;
}

string Node::getName()
{
    return data.name;
}

int Node::getId()
{
    return data.id;
}

int Node::getPrice()
{
    return data.price;
}

void Node::setName(string name)
{
    this->data.name = name;
}

void Node::setId(int id)
{
    this->data.id = id;
}

void Node::setPrice(int price)
{
    this->data.price = price;
}




