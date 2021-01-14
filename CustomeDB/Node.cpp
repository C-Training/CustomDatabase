#include "Node.h"

Node::Node(int id, string name, int price) {
    this->data.setId(id);
    this->data.setName(name);
    this->data.setPrice(price);
}