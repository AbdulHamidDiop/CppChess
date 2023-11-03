#ifndef ECHEQUIER_H
#define ECHEQUIER_H
#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QMessageBox>
#include <memory>
#include "chessPiece.h"
#include "king.h"

namespace Model {
    class ChessPiece;
    class King;
    class Queen;
    class Knight;
    class Bishop;
    class Rook;
    class Pawn;
}
namespace View {
    class Board : public QWidget {
        Q_OBJECT

    public:
        Board(QWidget* parent = nullptr);

        void placePiece(int row, int col, std::shared_ptr<Model::ChessPiece>);
        void updateSquare(int row, int col);
        bool movePiece(int fromRow, int fromCol, int toRow, int toCol);
        void resetSquareColors();

        void showMessage(const QString& title, const QString& message);

        void checkForCheck();
        bool isKingInCheck(bool isWhite) const;

        std::shared_ptr<Model::ChessPiece> pieces[8][8];
        bool isWhiteTurn = true;

        Board* get();
    protected:
        void mousePressEvent(QMouseEvent* event) override;

    private:
        QGridLayout* layout;
        QLabel* squares[8][8];
        int selectedRow = -1;
        int selectedCol = -1;

        bool isMoveBlocked(int fromRow, int fromCol, int toRow, int toCol) const;

    };
}
#endif 