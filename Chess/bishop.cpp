#include "bishop.h"

namespace Model {

    Bishop::Bishop(bool isWhite, View::Board* board) : ChessPiece(isWhite, board) {}

    QString Bishop::getUnicodeSymbol() const {
        return isWhite() ? QString("<span style='font-size:30pt; color:#AAAAAA;'>♗</span>") : QString("<span style='font-size:30pt; color:#000000;'>♝</span>");
    }

    bool Bishop::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        return abs(fromRow - toRow) == abs(fromCol - toCol);
    }
}