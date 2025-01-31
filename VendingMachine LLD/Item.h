#ifndef ITEMP_H
#define ITEMP_H

#include <iostream>
#include <string>

enum ItemType {
  COKE,
  PEPSI,
  WATER,
  SODA,
};

class Item {
private:
  ItemType type;
  int price;

public:
  Item() : type(WATER), price(0) {}

  Item(ItemType type, int price) {
    this->type = type;
    this->price = price;
  }
  ItemType getType() { return type; }
  int getPrice() { return price; }
  void setPrice(int price) { this->price = price;return; }
  void setType(ItemType type) { this->type = type; return; }
  std::string getName(ItemType type){
    switch (type){
      case COKE:
        return "Coke";
      case PEPSI:
        return "Pepsi";
      case WATER:
        return "Water";
      case SODA:
        return "Soda";
      default:
        return "Unknown";
    }
  }
};

#endif