#include "chessPiece.h"

namespace Model {
    ChessPiece::ChessPiece(bool isWhite, View::Board* board) : isWhite_(isWhite), board(board) {}
    bool ChessPiece::isWhite() const { return isWhite_; }
    bool ChessPiece::canLeap() { return false; }

    bool ChessPiece::isMoveCausingCheck(int fromRow, int fromCol, int toRow, int toCol) {

        std::shared_ptr<ChessPiece> capturedPiece = board->pieces[toRow][toCol];
        board->pieces[toRow][toCol] = board->pieces[fromRow][fromCol];
        board->pieces[fromRow][fromCol] = nullptr;

        if (board->isKingInCheck(board->isWhiteTurn)) {

            board->pieces[fromRow][fromCol] = board->pieces[toRow][toCol];
            board->pieces[toRow][toCol] = capturedPiece;
            return true;
        }

        board->pieces[fromRow][fromCol] = board->pieces[toRow][toCol];
        board->pieces[toRow][toCol] = capturedPiece;
        return false;
    }
}