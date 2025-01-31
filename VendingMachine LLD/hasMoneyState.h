#ifndef HAS_MONEY_STATE_H
#define HAS_MONEY_STATE_H
#include "Coins.h"
#include "Item.h"
#include "SelectionState.h"
#include "State.h"
#include "VendingMachine.h"
#include "iostream"
#include "IdleState.h"


class HasMoneyState : public State {
public:
  HasMoneyState() {
    std::cout << "Currently Vending Machine is in HasMoney State" << std::endl;
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