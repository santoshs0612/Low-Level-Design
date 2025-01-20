#include <iostream>
#include<bits/stdc++.h>
#include "board.h"
#include "playingPiece.h"
#include "player.h"
#include "tiktaktoe.h"

int main() {
  
  
  
  std::cout << "Hello to Tik Tak Toe Game\n";

  TikTakToe *game  = new TikTakToe();
  game->startGame();


    return 0;
}