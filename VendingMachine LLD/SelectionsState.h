#ifndef SELCTION_STATE_H
#define SELCTION_STATE_H

#include "Coins.h"
#include "Item.h"
#include "State.h"
#include <iostream>
#include <vector>

class VendingMachine;  // Forward declaration
class DespenceState;   // Forward declaration

class SelectionState : public State {
public:
  SelectionState() {
    std::cout << "Currently Vending Machine is in Product Selection State"
              << std::endl;
  }
  void clickOnInertCoinButton(VendingMachine *vendingMachine) override;
  void startProductSelectButton(VendingMachine *vendingMachine) override;
  void insertCoinButton(VendingMachine *vendingMachine, Coins coin) override;
  void choseProductButton(VendingMachine *vendingMachine, int codeNumber) override;
  int getChange(int returnChangeMoney) override;
  Item *despenceProduct(VendingMachine *vendingMachine, int codeNumber) override;
  std::vector<Coins> returnFullMoney(VendingMachine *vendingMachine) override;
  void updateInventery(VendingMachine *vendingMachine, Item item, int codeNumber) override;
};

#endif
