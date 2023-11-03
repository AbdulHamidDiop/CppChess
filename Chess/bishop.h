#ifndef BISHOP_H
#define BISHOP_H
#include "chessPiece.h"

namespace Model {

    class Bishop : public ChessPiece {
    public:
        Bishop(bool isWhite, View::Board* board);
        QString getUnicodeSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol)const override;
    };
}
#endif 