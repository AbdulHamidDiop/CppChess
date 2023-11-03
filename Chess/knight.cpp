#include "knight.h"

namespace Model {

    Knight::Knight(bool isWhite, View::Board* board) : ChessPiece(isWhite, board) {}
    bool Knight::canLeap() { return true; }

    QString Knight::getUnicodeSymbol() const {
        return isWhite() ? QString("<span style='font-size:30pt; color:#AAAAAA;'>♘</span>") : 
                           QString("<span style='font-size:30pt; color:#000000;'>♞</span>");
    }

    bool Knight::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        int rowDiff = abs(fromRow - toRow);
        int colDiff = abs(fromCol - toCol);

        if ((rowDiff == 1 && colDiff == 2) || (rowDiff == 2 && colDiff == 1)) {
            return true;
        }
        else {
            return false;
        }
    }
}