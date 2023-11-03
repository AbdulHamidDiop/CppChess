#ifndef KING_H
#define KING_H
#include "chessPiece.h"

namespace View {
    class Board;
}

namespace Model {

    class King : public ChessPiece {
    public:
        King(bool isWhite, View::Board* board);
        QString getUnicodeSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
        static int instanceCount;
        ~King();
    };
}
#endif 

