#ifndef ITEMSHELF_H
#define ITEMSHELF_H

#include "Item.h"


class ItemShelf{

  private:
    int code;
    Item* item;
    bool isSoldOut;
  public:
    ItemShelf() : code(0), item(nullptr), isSoldOut(false) {}  

    ItemShelf(int code){
      this->code = code;
      this->item = nullptr;
      this->isSoldOut = false;
    }
    int getCode(){
      return code;
    }
    void setCode(int code){
      this->code = code;
    }
    Item* getItem(){
      return item;
    }
    void setItem(Item *item){
      this->item = item;
    }
    bool getIsSoldOut(){
      return isSoldOut;
    }
    void setIsSoldOut(bool isSoldOut){
      this->isSoldOut = isSoldOut;
    }

};


#endif
