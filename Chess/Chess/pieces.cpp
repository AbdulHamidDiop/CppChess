#include "pieces.h"

namespace Model {
    int King::instanceCount;
    ChessPiece::ChessPiece(bool isWhite) : isWhite_(isWhite) {}
    bool ChessPiece::isWhite() const { return isWhite_; }
    ///////////////////////////////////////////////////////////////////////////////

    King::King(bool isWhite) : ChessPiece(isWhite) {
        if (instanceCount >= 2) {
            throw std::runtime_error("Cannot have more than 2 kings!");
        }
        instanceCount++;
    }
    King::~King() {
        instanceCount--;
    }
    QString King::getUnicodeSymbol() const {
        return isWhite() ? QString("<span style='font-size:30pt; color:#AAAAAA;'>♔</span>") : QString("<span style='font-size:30pt; color:#000000;'>♚</span>");
    }

    bool King::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        int rowDifference = abs(fromRow - toRow);
        int colDifference = abs(fromCol - toCol);
        return rowDifference <= 1 && colDifference <= 1;
    }
    /////////////////////////////////////////////////////////////////////////////

    Bishop::Bishop(bool isWhite) : ChessPiece(isWhite) {}

    QString Bishop::getUnicodeSymbol() const {
        return isWhite() ? QString("<span style='font-size:30pt; color:#AAAAAA;'>♗</span>") : QString("<span style='font-size:30pt; color:#000000;'>♝</span>");
    }

    bool Bishop::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        return abs(fromRow - toRow) == abs(fromCol - toCol);
    }
    ////////////////////////////////////////////////////////////////////////////

    Rook::Rook(bool isWhite) : ChessPiece(isWhite) {}

    QString Rook::getUnicodeSymbol() const {
        return isWhite() ? QString("<span style='font-size:30pt; color:#AAAAAA;'>♖</span>") : QString("<span style='font-size:30pt; color:#000000;'>♜</span>");
    }

    bool Rook::isValidMove(int fromRow, int fromCol, int toRow, int toCol) const {
        return fromRow == toRow || fromCol == toCol;
    }
}