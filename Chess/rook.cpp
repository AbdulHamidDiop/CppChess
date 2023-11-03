#include "rook.h"

namespace Model {

    Rook::Rook(bool isWhite, View::Board* board) : ChessPiece(isWhite, board) {}

    QString Rook::getUnicodeSymbol() const {
        return isWhite() ? QString("<span style='font-size:30pt; color:#AAAAAA;'>♖</span>") : 
                           QString("<span style='font-size:30pt; color:#000000;'>♜</span>");
    }

    bool Rook::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        return fromRow == toRow || fromCol == toCol;
    }
}