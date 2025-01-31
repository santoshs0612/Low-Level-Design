#include "SelectionState.h"
#include "VendingMachine.h"
#include "DespencingState.h"
#include "IdleState.h"
#include "hasMoneyState.h"



void IdleState:: clickOnInertCoinButton(VendingMachine *vendingMachine)  {
  vendingMachine->setVendingState(new HasMoneyState());
}
void IdleState::startProductSelectButton(VendingMachine *vendingMachine)  {
  throw "You can't start product select button in Idle State";
}

void IdleState::insertCoinButton(VendingMachine *vendingMachine, Coins coin)  {
  throw "You can't insert coin in Idle State";
}

void IdleState::choseProductButton(VendingMachine *vendingMachine,
                        int codeNumber)  {
  throw "You can't chose product in Idle State";
}

int IdleState::getChange(int returnChangeMoney)  {
  throw "You can't get change in Idle State";
}

Item* IdleState::despenceProduct(VendingMachine *vendingMachine,
                      int codeNumber)  {
  throw "You can't despence product in Idle State";
}

std::vector<Coins> IdleState::returnFullMoney(VendingMachine *vendingMachine)  {
  throw "You  can't return full money";
}
void IdleState::updateInventery(VendingMachine *vendingMachine, Item item,
                     int codeNumber)  {
  throw "You Cant Update Inventery in Idle State";
}