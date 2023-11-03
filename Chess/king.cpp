#include "king.h"

namespace Model{

    int King::instanceCount;
    King::King(bool isWhite, View::Board* board) : ChessPiece(isWhite, board) {
        if (instanceCount >= 2) {
            throw std::runtime_error("Cannot have more than 2 kings!");
        }
        instanceCount++;
    }

    King::~King() {
        instanceCount--;
    }

    QString King::getUnicodeSymbol() const {
        return isWhite() ? QString("<span style='font-size:30pt; color:#AAAAAA;'>♔</span>") : 
                           QString("<span style='font-size:30pt; color:#000000;'>♚</span>");
    }

    bool King::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        int rowDifference = abs(fromRow - toRow);
        int colDifference = abs(fromCol - toCol);
        return rowDifference <= 1 && colDifference <= 1;
    }
}