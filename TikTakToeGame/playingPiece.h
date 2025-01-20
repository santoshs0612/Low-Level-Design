#ifndef PLAYING_PIECE_H
#define PLAYING_PIECE_H

enum PieceType { X, O };

class PlayingPiece {

  PieceType type;

public:
  PlayingPiece(PieceType type) { this->type = type; }

  PieceType getType() { return type; }
};

class PlayingPieceX : public PlayingPiece {

public:
  PlayingPieceX() : PlayingPiece(X) {}
};
class PlayingPieceO : public PlayingPiece {

public:
  PlayingPieceO() : PlayingPiece(O) {}
};
#endif // PLAYING_PIECE_H