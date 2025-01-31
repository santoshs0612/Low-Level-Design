#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "ItemShelf.h"
#include <vector>

class Inventory {
private:
  std::vector<ItemShelf> itemShelfs;

public:
  Inventory(int itemCount) {
    itemShelfs.resize(itemCount);
    initialEmptyInventory();
  }
  void initialEmptyInventory() {
    int startCode = 101;
    for (int i = 0; i < itemShelfs.size(); i++) {
      itemShelfs[i].setCode(startCode);
      itemShelfs[i].setIsSoldOut(false);
      startCode++;
    }
  }
  void addItem(Item item, int codeNumber) {
    for (ItemShelf itemShelf : itemShelfs) {
      if (itemShelf.getCode() == codeNumber) {
        if (itemShelf.getIsSoldOut()) {
          itemShelf.setItem(&item);
          itemShelf.setIsSoldOut(true);
        } else {
          std::cout << "Alreay have this item" << std::endl;
        }
      }
    }
  }
  ItemShelf* getItem(int codeNumber) {
    for (ItemShelf &itemShelf : itemShelfs) {
      if (itemShelf.getCode() == codeNumber) {
        if (itemShelf.getIsSoldOut()) {
          return &itemShelf;
        } else {
          std::cout << "No Item" << std::endl;
        }
      }
    }
    return NULL;
  }
  std::vector<ItemShelf>* getInventory() { return &itemShelfs; }
};

#endif