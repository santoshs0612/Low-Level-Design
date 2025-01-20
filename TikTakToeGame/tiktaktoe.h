#ifndef TIKTAKTOE_H
#define TIKTAKTOE_H

#include "board.h"
#include "player.h"
#include "playingPiece.h"
#include <deque>
#include <string>
using namespace std;

class TikTakToe {

private:
public:
  deque<Player *> players;
  Board *gameBoard;
  TikTakToe() { initializeGame(); }
  void initializeGame() {
    gameBoard = new Board(3);
    PlayingPiece crossPiece = PlayingPieceX();
    PlayingPiece circlePiece = PlayingPieceO();
    Player *player1 = new Player("Player 1", crossPiece);
    Player *player2 = new Player("Player 2", circlePiece);
    players.push_back(player1);
    players.push_back(player2);
  }

  string startGame() {
    // bool noWiner = false;
    bool winner = false;
    Player *player;
    // gameBoard->printBoard();
    while (!winner) {

      player = players.front();
      players.pop_front();

      gameBoard->printBoard();

      // check for the free space

      vector<pair<int, int>> freecells = gameBoard->getFreeCells();
      // cout << "Hello " << freecells.size();
      if (freecells.size() == 0) {
        winner = true;
        continue;
      }

      cout << "It's " << player->getName() << " turn" << endl;
      cout << "Enter row and column" << endl;
      int row, col;
      // cout<< "Hello";
      cin >> row;
      cout << "Enter Column" << endl;
      cin >> col;
      // cout << row << " " << col;

      PlayingPiece *temp = new PlayingPiece(X);
      *temp = (player->getPiece());
      bool val = gameBoard->setPiece(row, col, temp);
      if (val == false) {
        cout << "Invalid move" << endl;
        players.push_front(player);
        continue;
      }
      // check for the winner

      players.push_back(player);
      *temp = player->getPiece();
      if (winnerCheck(row, col, temp)) {
        winner = true;
        return player->getName();
      }
      // continue;
    }
    return "Tie";
  }

  bool winnerCheck(int row, int col, PlayingPiece *piece) {

    int count = 0;
    int size = gameBoard->getSize();
    // check for the row
    for (int i = 0; i < size; i++) {
      if (gameBoard->getPiece(row, i) != nullptr &&
          gameBoard->getPiece(row, i)->getType() == piece->getType()) {
        // cout << "Hello";
        count++;
      }
    }
    if (count == size) {
      return true;
    }
    // check for the column
    count = 0;
    for (int i = 0; i < size; i++) {
      if (gameBoard->getPiece(i, col) != nullptr &&
          gameBoard->getPiece(i, col)->getType() == piece->getType()) {
        count++;
      }
    }
    if (count == size) {
      return true;
    }
    // check for the diagonal
    count = 0;
    for (int i = 0; i < size; i++) {
      if (gameBoard->getPiece(i, i) != nullptr &&
          gameBoard->getPiece(i, i)->getType() == piece->getType()) {
        count++;
      }
    }
    if (count == size) {
      return true;
    }

    // check for the diagonal
    count = 0;
    for (int i = 0; i < size; i++) {
      if (gameBoard->getPiece(i, size - 1 - i) != nullptr &&
          gameBoard->getPiece(i, size - 1 - i)->getType() == piece->getType()) {
      }
    }
    if (count == size) {
      return true;
    }
    return false;
  }
};

#endif // BOARDS_H