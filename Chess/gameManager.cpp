#include "gameManager.h"

GameManager::GameManager(View::Board* board) : board_(board) { /*board->setManager(this);*/ }

std::shared_ptr<Model::King> GameManager::createKing(bool bOw) {
    try {
        std::shared_ptr<Model::King> king(new Model::King(bOw, board_));
        return king;
    }
    catch (const std::runtime_error& e) {
        board_->showMessage("Error", e.what());
        return nullptr;
    }
}

std::unique_ptr<QWidget> GameManager::startWindow(QWidget& selectionWindow) {

    std::unique_ptr<QWidget> startWindowPtr(new QWidget);
    startWindowPtr->setWindowTitle("Chess");
    startWindowPtr->setGeometry(565, 350, 400, 200);

    QPushButton* startButton = new QPushButton("Start Game", startWindowPtr.get());
    startButton->setGeometry(100, 60, 200, 40);

    QObject::connect(startButton, &QPushButton::clicked, [&]() {
        startWindowPtr->close();
        selectionWindow.show();
        });

    return startWindowPtr;
}

std::unique_ptr<QWidget> GameManager::selectionWindow() {

    std::unique_ptr<QWidget> selectionWindow(new QWidget);
    selectionWindow->setWindowTitle("Please choose game board layout");
    selectionWindow->setGeometry(565, 275, 400, 400);

    QPushButton* launchButton = new QPushButton("Launch game", selectionWindow.get());
    launchButton->setGeometry(100, 220, 200, 50);

    QPushButton* standardButton = new QPushButton("Standard layout", selectionWindow.get());
    standardButton->setGeometry(100, 40, 200, 40);

    QPushButton* kingsQueens = new QPushButton("Kings & Queens", selectionWindow.get());
    kingsQueens->setGeometry(100, 80, 200, 40);

    QPushButton* knightAttack = new QPushButton("Knight Attack", selectionWindow.get());
    knightAttack->setGeometry(100, 120, 200, 40);

    QPushButton* endGame = new QPushButton("EndGame", selectionWindow.get());
    endGame->setGeometry(100, 160, 200, 40);

    QObject::connect(launchButton, &QPushButton::clicked, [&]() {
        placePieces();

        QString message = "green: selected piece \n\n red: not turn to play \n\n light red: invalid move \n\n yellow: valid moves";
        board_->showMessage("Color code", message);

        selectionWindow->close();
        board_->show();
        });

    QObject::connect(standardButton, &QPushButton::clicked, [&]() {
        configuration = 1;
        });

    QObject::connect(kingsQueens, &QPushButton::clicked, [&]() {
        configuration = 2;
        });

    QObject::connect(knightAttack, &QPushButton::clicked, [&]() {
        configuration = 3;
        });

    QObject::connect(endGame, &QPushButton::clicked, [&]() {
        configuration = 4;
        });


    return selectionWindow;
}

void GameManager::placePieces() {
	
    using Model::ChessPiece;
    using Model::King;
    using Model::Queen;
    using Model::Knight;
    using Model::Bishop;
    using Model::Rook;
    using Model::Pawn;
    using namespace std;

    shared_ptr<ChessPiece> whiteKing = createKing(true);
    shared_ptr<ChessPiece> blackKing = createKing(false);
    
    shared_ptr<ChessPiece> whiteQueen(new Queen(true, board_));
    shared_ptr<ChessPiece> blackQueen(new Queen(false, board_));
    
    shared_ptr<ChessPiece> whiteKnight1(new Knight(true, board_));
    shared_ptr<ChessPiece> whiteKnight2(new Knight(true, board_));
    shared_ptr<ChessPiece> blackKnight1(new Knight(false, board_));
    shared_ptr<ChessPiece> blackKnight2(new Knight(false, board_));
    
    shared_ptr<ChessPiece> whiteBishop1(new Bishop(true, board_));
    shared_ptr<ChessPiece> whiteBishop2(new Bishop(true, board_));
    shared_ptr<ChessPiece> blackBishop1(new Bishop(false, board_));
    shared_ptr<ChessPiece> blackBishop2(new Bishop(false, board_));
    
    shared_ptr<ChessPiece> whiteRook1(new Rook(true, board_));
    shared_ptr<ChessPiece> whiteRook2(new Rook(true, board_));
    shared_ptr<ChessPiece> blackRook1(new Rook(false, board_));
    shared_ptr<ChessPiece> blackRook2(new Rook(false, board_));
    
    shared_ptr<ChessPiece> whitePawn1(new Pawn(true, board_));
    shared_ptr<ChessPiece> whitePawn2(new Pawn(true, board_));
    shared_ptr<ChessPiece> whitePawn3(new Pawn(true, board_));
    shared_ptr<ChessPiece> whitePawn4(new Pawn(true, board_));
    shared_ptr<ChessPiece> whitePawn5(new Pawn(true, board_));
    shared_ptr<ChessPiece> whitePawn6(new Pawn(true, board_));
    shared_ptr<ChessPiece> whitePawn7(new Pawn(true, board_));
    shared_ptr<ChessPiece> whitePawn8(new Pawn(true, board_));
    shared_ptr<ChessPiece> blackPawn1(new Pawn(false, board_));
    shared_ptr<ChessPiece> blackPawn2(new Pawn(false, board_));
    shared_ptr<ChessPiece> blackPawn3(new Pawn(false, board_));
    shared_ptr<ChessPiece> blackPawn4(new Pawn(false, board_));
    shared_ptr<ChessPiece> blackPawn5(new Pawn(false, board_));
    shared_ptr<ChessPiece> blackPawn6(new Pawn(false, board_));
    shared_ptr<ChessPiece> blackPawn7(new Pawn(false, board_));
    shared_ptr<ChessPiece> blackPawn8(new Pawn(false, board_));

    switch (configuration) {

        case 1: //standard

            board_->placePiece(0, 4, blackKing);
            board_->placePiece(7, 4, whiteKing);

            board_->placePiece(7, 3, whiteQueen);
            board_->placePiece(0, 3, blackQueen);

            board_->placePiece(7, 2, whiteBishop1);
            board_->placePiece(7, 5, whiteBishop2);
            board_->placePiece(0, 2, blackBishop1);
            board_->placePiece(0, 5, blackBishop2);

            board_->placePiece(7, 0, whiteRook1);
            board_->placePiece(7, 7, whiteRook2);
            board_->placePiece(0, 0, blackRook1);
            board_->placePiece(0, 7, blackRook2);

            board_->placePiece(7, 1, whiteKnight1);
            board_->placePiece(7, 6, whiteKnight2);
            board_->placePiece(0, 1, blackKnight1);
            board_->placePiece(0, 6, blackKnight2);

            board_->placePiece(6, 0, whitePawn1);
            board_->placePiece(6, 1, whitePawn2);
            board_->placePiece(6, 2, whitePawn3);
            board_->placePiece(6, 3, whitePawn4);
            board_->placePiece(6, 4, whitePawn5);
            board_->placePiece(6, 5, whitePawn6);
            board_->placePiece(6, 6, whitePawn7);
            board_->placePiece(6, 7, whitePawn8);

            board_->placePiece(1, 0, blackPawn1);
            board_->placePiece(1, 1, blackPawn2);
            board_->placePiece(1, 2, blackPawn3);
            board_->placePiece(1, 3, blackPawn4);
            board_->placePiece(1, 4, blackPawn5);
            board_->placePiece(1, 5, blackPawn6);
            board_->placePiece(1, 6, blackPawn7);
            board_->placePiece(1, 7, blackPawn8);
            break;

        case 2: //Kings&Queens

            board_->placePiece(0, 4, blackKing);
            board_->placePiece(7, 4, whiteKing);

            board_->placePiece(7, 3, whiteQueen);
            board_->placePiece(0, 3, blackQueen);
            break;

        case 3: //Knight Attack

            board_->placePiece(0, 3, blackKing);
            board_->placePiece(7, 4, whiteKing);

            board_->placePiece(5, 1, whiteKnight1);
            board_->placePiece(5, 6, whiteKnight2);
            board_->placePiece(2, 1, blackKnight1);
            board_->placePiece(2, 6, blackKnight2);

            board_->placePiece(5, 0, whitePawn1);
            board_->placePiece(6, 1, whitePawn2);
            board_->placePiece(5, 2, whitePawn3);
            board_->placePiece(6, 6, whitePawn4);
            board_->placePiece(5, 5, whitePawn5);
            board_->placePiece(5, 7, whitePawn6);


            board_->placePiece(2, 0, blackPawn1);
            board_->placePiece(1, 1, blackPawn2);
            board_->placePiece(2, 2, blackPawn3);
            board_->placePiece(1, 6, blackPawn4);
            board_->placePiece(2, 5, blackPawn5);
            board_->placePiece(2, 7, blackPawn6);
            break;

        case 4: //endGame

            board_->placePiece(0, 3, blackKing);
            board_->placePiece(7, 4, whiteKing);

            board_->placePiece(5, 7, whiteRook1);
            board_->placePiece(1, 3, blackRook1);

            board_->placePiece(5, 1, whiteKnight1);
            board_->placePiece(0, 2, blackBishop1);

            board_->placePiece(6, 4, whitePawn1);
            board_->placePiece(6, 7, whitePawn2);
            board_->placePiece(4, 4, blackPawn1);
            board_->placePiece(1, 1, blackPawn2);
            break;

    }
}