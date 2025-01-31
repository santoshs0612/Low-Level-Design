#include "SelectionState.h"
#include "VendingMachine.h"
#include "DespencingState.h"
#include "IdleState.h"

void SelectionState::clickOnInertCoinButton(VendingMachine *vendingMachine) {
  throw "You can't click on inert coin button in Product Selection State";
}

void SelectionState::startProductSelectButton(VendingMachine *vendingMachine) {
  throw "You can't start product select button in Product Selection State";
}

void SelectionState::insertCoinButton(VendingMachine *vendingMachine, Coins coin) {
  throw "You can't insert coin in Product Selection State";
}

void SelectionState::choseProductButton(VendingMachine *vendingMachine, int codeNumber) {
  ItemShelf *itemShelf = vendingMachine->getInventory()->getItem(codeNumber);
  Item *item = itemShelf->getItem();

  int paidByuser = 0;
  for (Coins &coin : *(vendingMachine->getCoinList())) {
    paidByuser += coin;
  }

  if (paidByuser < item->getPrice()) {
    std::cout << "Insufficient amount paid" << std::endl;
    std::cout << "Product selected Price is " << item->getPrice() << std::endl;
    std::cout << "Amount paid by user is " << paidByuser << std::endl;
    throw "Insufficient amount paid";
  } else {
    if (paidByuser > item->getPrice()) {
      int returnChangeMoney = paidByuser - item->getPrice();
      getChange(returnChangeMoney);
    }
    vendingMachine->setVendingState(new DespenceState(vendingMachine, codeNumber));
  }
}

int SelectionState::getChange(int returnChangeMoney) {
  std::cout << "Returned the change in Despense Tray " << returnChangeMoney << std::endl;
  return returnChangeMoney;
}

Item *SelectionState::despenceProduct(VendingMachine *vendingMachine, int codeNumber) {
  throw "You can't dispense product in Product Selection State";
}

std::vector<Coins> SelectionState::returnFullMoney(VendingMachine *vendingMachine) {
  std::cout << "Returned the full amount to the dispense Tray" << std::endl;
  vendingMachine->setVendingState(new IdleState());
  return *(vendingMachine->getCoinList());
}

void SelectionState::updateInventery(VendingMachine *vendingMachine, Item item, int codeNumber) {
  throw "You can't update inventory in Product Selection State";
}
