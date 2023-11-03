#ifndef QUEEN_H
#define QUEEN_H
#include "chessPiece.h"

namespace Model {

    class Queen : public ChessPiece {
    public:
        Queen(bool isWhite, View::Board* board);
        QString getUnicodeSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };
}
#endif 
