#ifndef DESPENCE_STATE_H
#define DESPENCE_STATE_H
#include "Coins.h"
#include "Item.h"
#include "State.h"
#include "iostream"

class VendingMachine;

class DespenceState : public State {
public:
  DespenceState(VendingMachine *vendingMachine, int codeNumber) {
    std::cout << "Currently Vending Machine is in Despence State" << std::endl;
    despenceProduct(vendingMachine, codeNumber);
  }
  void clickOnInertCoinButton(VendingMachine *vendingMachine) override;
  void startProductSelectButton(VendingMachine *vendingMachine) override;
  void insertCoinButton(VendingMachine *vendingMachine, Coins coin) override;
  void choseProductButton(VendingMachine *vendingMachine,
                          int codeNumber) override;
  int getChange(int returnChangeMoney) override;
  Item *despenceProduct(VendingMachine *vendingMachine,
                        int codeNumber) override;
  std::vector<Coins> returnFullMoney(VendingMachine *vendingMachine) override;
  void updateInventery(VendingMachine *vendingMachine, Item item,
                       int codeNumber) override;
};

#endif