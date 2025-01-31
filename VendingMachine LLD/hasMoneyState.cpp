
#include "hasMoneyState.h"
#include "DespencingState.h"
#include "IdleState.h"
#include "SelectionState.h"
#include "VendingMachine.h"

void HasMoneyState::clickOnInertCoinButton(VendingMachine *vendingMachine) {
  throw "You can't click on inert coin button in HasMoney State";
}
void HasMoneyState::startProductSelectButton(VendingMachine *vendingMachine) {
  vendingMachine->setVendingState(new SelectionState());
}

void HasMoneyState::insertCoinButton(VendingMachine *vendingMachine,
                                     Coins coin) {
  std::cout << "Accept the Coin" << std::endl;
  (vendingMachine->getCoinList())->push_back(coin);
}

void HasMoneyState::choseProductButton(VendingMachine *vendingMachine,
                                       int codeNumber) {
  throw "You can't chose product in HasMoney State";
}

int HasMoneyState::getChange(int returnChangeMoney) {
  throw "You can't get change in Idle State";
}

Item* HasMoneyState::despenceProduct(VendingMachine *vendingMachine,
                                     int codeNumber) {
  throw "You can't despence product in Idle State";
}

std::vector<Coins>
HasMoneyState::returnFullMoney(VendingMachine *vendingMachine) {
  std::cout << "Returned the full amount to the despence Tray" << std::endl;
  vendingMachine->setVendingState(new IdleState());
  return *(vendingMachine->getCoinList());
}
void HasMoneyState::updateInventery(VendingMachine *vendingMachine, Item item,
                                    int codeNumber) {
  throw "You Cant Update Inventery in Idle State";
}