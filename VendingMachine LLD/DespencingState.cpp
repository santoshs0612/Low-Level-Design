
#include "VendingMachine.h"
#include "DespencingState.h"
#include "IdleState.h"

void DespenceState::clickOnInertCoinButton(VendingMachine *vendingMachine) {
  throw "You can't click on inert coin button in Despence State";
}
void DespenceState::startProductSelectButton(VendingMachine *vendingMachine) {
  throw "You can't start product select button in Despence State";
}

void DespenceState::insertCoinButton(VendingMachine *vendingMachine, Coins coin) {
  throw "You can't insert coin in Despence State";
}

void DespenceState::choseProductButton(VendingMachine *vendingMachine, int codeNumber) {
  throw "You can't chose product in Despence State";
}

int DespenceState::getChange(int returnChangeMoney) {
  throw "You can't get change in Despence State";
}

Item* DespenceState::despenceProduct(VendingMachine *vendingMachine, int codeNumber) {

  std::cout << "Product has been despenced" << std::endl;
  ItemShelf *itemShelf = vendingMachine->getInventory()->getItem(codeNumber);
  Item *item = itemShelf->getItem();
  itemShelf->setIsSoldOut(false);
  State *idle = new IdleState(vendingMachine);
  vendingMachine->setVendingState(idle);
  return item;
}

std::vector<Coins> DespenceState::returnFullMoney(VendingMachine *vendingMachine) {
  throw "You can't return full money in Despence State";
}
void DespenceState::updateInventery(VendingMachine *vendingMachine, Item item,
                     int codeNumber) {
  throw "You Cant Update Inventery in Despence State";
}