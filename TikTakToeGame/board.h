#ifndef BOARD_H
#define BOARD_H

#include "playingPiece.h"
#include <iostream>
#include <vector>
using namespace std;
class Board {

private:
  int size;
  vector<vector<PlayingPiece *>> board;

public:
  Board(int size) {
    this->size = size;
    for (int i = 0; i < size; i++) {
      vector<PlayingPiece *> row;
      for (int j = 0; j < size; j++) {
        row.push_back(nullptr);
      }
      board.push_back(row);
    }
  }
  void printBoard() {
    for (int i = 0; i < size; i++) {
      cout << "|";
      for (int j = 0; j < size; j++) {
        if (board[i][j] == nullptr) {
          cout << "    "
               << "|";
        } else {
          cout << board[i][j]->getType() << "  |";
        }
      }
      cout << endl;
    }
  }
  PlayingPiece getPiece(int row, int col) { return *board[row][col]; }
  bool setPiece(int row, int col, PlayingPiece *piece) {
    if (board[row][col] == nullptr) {
      board[row][col] = piece;
      return true;
    } else {
      return false;
    }
  }
  vector<pair<int, int>> getFreeCells() {
    vector<pair<int, int>> freeCells;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (board[i][j] == nullptr) {
          freeCells.push_back(make_pair(i, j));
        }
      }
    }
    return freeCells;
  }
  int getSize() { return size; }
};

#endif // BORAD_H
