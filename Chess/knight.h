#ifndef KNIGHT_H
#define KNIGHT_H
#pragma once
#include "chessPiece.h"

namespace Model {

    class Knight : public ChessPiece {
    public:
        Knight(bool isWhite, View::Board* board);
        bool canLeap() override;
        QString getUnicodeSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };
}
#endif 