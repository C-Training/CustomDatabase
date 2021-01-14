#include "Item.h"

void Item::setName(string name) {
    this->name = name;
}
string Item::getName() {
    return name;
}
void Item::setId(int id) {
    this->id = id;
}
int Item::getId() {
    return id;
}
void Item::setPrice(int price) {
    this->price = price;
}
int Item::getPrice() {
    return price;
}