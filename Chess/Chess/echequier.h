#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QMessageBox>
#include "Pieces.h"
namespace View {

    class Board : public QWidget {
        Q_OBJECT

    public:
        Board(QWidget* parent = nullptr);

        void placePiece(int row, int col, Model::ChessPiece* piece);
        void updateSquare(int row, int col);
        bool movePiece(int fromRow, int fromCol, int toRow, int toCol);
        void resetSquareColors();

        void showMessage(const QString& title, const QString& message);

        void checkForCheck();
        bool isKingInCheck(bool isWhite) const;

    protected:
        void mousePressEvent(QMouseEvent* event) override;

    private:
        QGridLayout* layout;
        QLabel* squares[8][8];
        Model::ChessPiece* pieces[8][8];
        int selectedRow = -1;
        int selectedCol = -1;
        bool isWhiteTurn = true;

        bool isMoveBlocked(int fromRow, int fromCol, int toRow, int toCol) const;

    };
}