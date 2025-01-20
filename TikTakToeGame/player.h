#include "playingPiece.h"

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
class Player {
private:
public:
  std::string name;
  PlayingPiece piece;
  Player(std::string name, PlayingPiece piece) : piece(piece) {
    this->name = name;
  }
  std::string getName() { return name; }
  PlayingPiece getPiece() { return piece; }
  void setPiece(PlayingPiece piece) { this->piece = piece; }
  void setNmae(std::string name) { this->name = name; }
};

#endif // PLAYER_H