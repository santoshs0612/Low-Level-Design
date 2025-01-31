#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include "Coins.h"
#include "Item.h"
#include "ItemShelf.h"
#include "State.h"
// #include "IdleState.h"  // to avoid circular dependency 
#include "Inventory.h"
#include <vector>

class IdleState;

class VendingMachine {
private:
  State *state = nullptr;
  Inventory *inventory;
  std::vector<Coins> coinList;

public:
  VendingMachine();
~VendingMachine();
  State *getVendingState() ;
  void setVendingState(State *state);
  Inventory *getInventory() ;
  void setInventory(Inventory *inventory) ;
  std::vector<Coins>* getCoinList() ;
  void setCoinList(std::vector<Coins> coinList) ;
};

#endif