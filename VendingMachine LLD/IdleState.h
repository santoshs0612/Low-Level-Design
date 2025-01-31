#ifndef IDLE_STATE_H
#define IDLE_STATE_H
#include "State.h"
#include "VendingMachine.h"
#include <iostream>
#include <vector>

class IdleState : public State {

public:
  IdleState() {
    std::cout << "Currently Vending Machine is in Idle State" << std::endl;
  }
  IdleState(VendingMachine *vendingMachine) {
    std::cout << "Currently Vending Machine is in Idle State" << std::endl;
    std::vector<Coins> coinsList;
    vendingMachine->setCoinList(coinsList);
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