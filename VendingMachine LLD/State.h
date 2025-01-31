

#ifndef STATE_H
#define STATE_H
#include "Coins.h"
#include "Item.h"
// #include "VendingMachine.h"
#include <vector>
class VendingMachine;

class State {
public:
  virtual ~State(){};
  virtual void clickOnInertCoinButton(VendingMachine *vendingMachine) = 0;
  virtual void startProductSelectButton(VendingMachine *vendingMachine) = 0;
  virtual void insertCoinButton(VendingMachine *vendingMachine, Coins coin) = 0;
  virtual void choseProductButton(VendingMachine *vendingMachine,
                                  int codeNumber) = 0;
  virtual int getChange(int returnChangeMoney) = 0;
  virtual Item *despenceProduct(VendingMachine *vendingMachine,
                                int codeNumber) = 0;
  virtual std::vector<Coins>
  returnFullMoney(VendingMachine *vendingMachine) = 0;
  virtual void updateInventery(VendingMachine *vendingMachine, Item item,
                               int codeNumber) = 0;
};

#endif