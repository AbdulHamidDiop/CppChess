#include "pawn.h"

namespace Model {

    Pawn::Pawn(bool isWhite, View::Board* board) : ChessPiece(isWhite, board) {}

    QString Pawn::getUnicodeSymbol() const {
        return isWhite() ? QString("<span style='font-size:30pt; color:#AAAAAA;'>♙</span>") : 
                           QString("<span style='font-size:30pt; color:#000000;'>♟</span>");
    }

    bool Pawn::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        if (fromRow < toRow && isWhite()) return false;
        if (fromRow > toRow && !isWhite()) return false;

        int colDifference = abs(fromCol - toCol);
        int rowDifference = abs(toRow - fromRow);

        if (colDifference == 1 && rowDifference == 1 && board->pieces[toRow][toCol] != nullptr) return true;
        else if ((colDifference > 0)) return false;

        if ((rowDifference == 2) && (fromRow == 1 || fromRow == 6)) return true;
        else if (rowDifference != 1) return false;

        if (board->pieces[toRow][toCol] != nullptr) return false;

        return true;
    }
}