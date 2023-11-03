#ifndef ROOK_H
#define ROOK_H
#pragma once
#include "chessPiece.h"

namespace Model {

    class Rook : public ChessPiece {
    public:
        Rook(bool isWhite, View::Board* board);
        QString getUnicodeSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };
}
#endif 