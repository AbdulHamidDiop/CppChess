#include "echequier.h" //nessaire de include avant 
#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <QString>
#include <stdexcept>

namespace View {
    class Board;
}

namespace Model {

    class ChessPiece {
    public:
        ChessPiece(bool isWhite, View::Board* board);
        virtual ~ChessPiece() = default;
        virtual QString getUnicodeSymbol() const = 0;
        bool isWhite() const;
        virtual bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const = 0;
        bool isMoveCausingCheck(int fromRow, int fromCol, int toRow, int toCol);
        virtual bool canLeap();
        View::Board* board;

    private:
        bool isWhite_;
    };

}
#endif 
