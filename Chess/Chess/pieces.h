#ifndef PIECES_H
#define PIECES_H
#pragma once
#include <QString>
#include <stdexcept>

namespace Model {

    class ChessPiece {
    public:
        ChessPiece(bool isWhite);
        virtual ~ChessPiece() = default;
        virtual QString getUnicodeSymbol() const = 0;
        bool isWhite() const;
        virtual bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const = 0;
    private:
        bool isWhite_;
    };

    class King : public ChessPiece {
    public:
        King(bool isWhite);
        QString getUnicodeSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
        static int instanceCount;
        ~King();
    };

    class Bishop : public ChessPiece {
    public:
        Bishop(bool isWhite);
        QString getUnicodeSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol)const override;
    };

    class Rook : public ChessPiece {
    public:
        Rook(bool isWhite);
        QString getUnicodeSymbol() const override;
        bool isValidMove(int fromRow, int fromCol, int toRow, int toCol) const override;
    };
}
#endif 