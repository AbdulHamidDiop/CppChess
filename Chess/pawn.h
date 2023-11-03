#ifndef PAWN_H
#define PAWN_H
#pragma once
#include "chessPiece.h"

namespace Model {

    class Pawn : public ChessPiece {
    public:
        Pawn(bool isWhite, View::Board* board);
        QString getUnicodeSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };
}
#endif 