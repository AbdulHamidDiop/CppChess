#include "queen.h"

namespace Model {

    Queen::Queen(bool isWhite, View::Board* board) : ChessPiece(isWhite, board) {}

    QString Queen::getUnicodeSymbol() const {
        return isWhite() ? QString("<span style='font-size:30pt; color:#AAAAAA;'>♕</span>") : 
                           QString("<span style='font-size:30pt; color:#000000;'>♛</span>");
    }

    bool Queen::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        int rowDifference = abs(fromRow - toRow);
        int colDifference = abs(fromCol - toCol);
        return rowDifference <= 8 && colDifference <= 8;
    }
}