#include "echequier.h"
namespace View {
    Board::Board(QWidget* parent) : QWidget(parent) {
        Model::King::instanceCount = 0;
        layout = new QGridLayout(this);
        layout->setSpacing(0);
        layout->setContentsMargins(0, 0, 0, 0);

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                squares[row][col] = new QLabel(this);
                squares[row][col]->setFixedSize(50, 50);
                squares[row][col]->setStyleSheet((row + col) % 2 == 0 ? "background-color: white;" : "background-color:#8B4513;");
                layout->addWidget(squares[row][col], row, col);
            }
        }
    }
    void Board::placePiece(int row, int col, Model::ChessPiece* piece) {
        pieces[row][col] = piece;
        if (piece != nullptr) {
            squares[row][col]->setText(piece->getUnicodeSymbol());
            squares[row][col]->setStyleSheet((row + col) % 2 == 0 ? "font-size: 40px; background-color: white;" : "font-size: 40px; background-color:#8B4513;");
        }
    }
    void Board::updateSquare(int row, int col) {
        Model::ChessPiece* piece = pieces[row][col];
        if (piece != nullptr) {
            squares[row][col]->setText(piece->getUnicodeSymbol());
            squares[row][col]->setStyleSheet((row + col) % 2 == 0 ? "font-size: 40px; background-color: white;" : "font-size: 40px; background-color:#8B4513;");
        }
        else {
            squares[row][col]->setText("");
            squares[row][col]->setStyleSheet((row + col) % 2 == 0 ? "background-color: white;" : "background-color:#8B4513;");
        }
    }

    void Board::showMessage(const QString& title, const QString& message) {
        QMessageBox::information(this, title, message);
    }


    bool Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
        resetSquareColors();
        Model::ChessPiece* movingPiece = pieces[fromRow][fromCol];

        if (movingPiece->isValidMove(fromRow, fromCol, toRow, toCol) && !isMoveBlocked(fromRow, fromCol, toRow, toCol)) {
            Model::ChessPiece* capturedPiece = pieces[toRow][toCol];
            if (capturedPiece != nullptr) {
                if (capturedPiece->isWhite() == movingPiece->isWhite()) {
                    return false;
                }
                capturedPiece = nullptr;
            }
            pieces[toRow][toCol] = movingPiece;
            pieces[fromRow][fromCol] = nullptr;
            updateSquare(fromRow, fromCol);
            updateSquare(toRow, toCol);
            return true;
        }
        return false;
    }
    void Board::checkForCheck() {
        bool isWhiteKingInCheck = isKingInCheck(true);
        bool isBlackKingInCheck = isKingInCheck(false);

        if (isWhiteKingInCheck || isBlackKingInCheck) {
            QString message = isWhiteKingInCheck ? "Le roi blanc est en Échec!" : "Le roi noir est en Échec!";
            showMessage("Échec", message);
        }
    }
    bool Board::isKingInCheck(bool isWhite) const {
        int kingRow = -1;
        int kingCol = -1;

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                Model::ChessPiece* piece = pieces[row][col];
                if (piece != nullptr && piece->isWhite() == isWhite && dynamic_cast<Model::King*>(piece) != nullptr) {
                    kingRow = row;
                    kingCol = col;
                    break;
                }
            }
            if (kingRow != -1 && kingCol != -1) {
                break;
            }
        }

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                Model::ChessPiece* piece = pieces[row][col];
                if (piece != nullptr && piece->isWhite() != isWhite) {
                    if (piece->isValidMove(row, col, kingRow, kingCol) && !isMoveBlocked(row, col, kingRow, kingCol)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    void Board::mousePressEvent(QMouseEvent* event) {
        int col = event->position().x() / 50;
        int row = event->position().y() / 50;

        if (selectedRow == -1 && selectedCol == -1) {
            if (pieces[row][col] != nullptr && pieces[row][col]->isWhite() == isWhiteTurn) {
                selectedRow = row;
                selectedCol = col;
                squares[row][col]->setStyleSheet("background-color: #FFD700;");

                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 8; ++j) {
                        if (pieces[row][col]->isValidMove(row, col, i, j)) {
                            squares[i][j]->setStyleSheet("background-color: #FFD700;");
                        }
                    }
                }
            }

        }
        else {
            if (movePiece(selectedRow, selectedCol, row, col)) {
                squares[selectedRow][selectedCol]->setStyleSheet((selectedRow + selectedCol) % 2 == 0 ? "background-color: white;" : "background-color:#8B4513;");
                isWhiteTurn = !isWhiteTurn;
                checkForCheck();
            }
            selectedRow = -1;
            selectedCol = -1;
        }
    }

    bool Board::isMoveBlocked(int fromRow, int fromCol, int toRow, int toCol) const {
        int rowStep = 0;
        int colStep = 0;

        if (fromRow < toRow) {
            rowStep = 1;
        }
        else if (fromRow > toRow) {
            rowStep = -1;
        }

        if (fromCol < toCol) {
            colStep = 1;
        }
        else if (fromCol > toCol) {
            colStep = -1;
        }

        int row = fromRow + rowStep;
        int col = fromCol + colStep;

        while (row != toRow || col != toCol) {
            if (pieces[row][col] != nullptr) {
                return true;
            }
            row += rowStep;
            col += colStep;
        }

        return false;
    }

    void Board::resetSquareColors() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                squares[i][j]->setStyleSheet((i + j) % 2 == 0 ? "background-color: white;" : "background-color:#8B4513;");

            }
        }
    }
}

