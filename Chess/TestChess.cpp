
#include "echequier.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "pawn.h"
#include "gameManager.h"
#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#ifdef TEST
#endif
using namespace Model;

class MockBoard : public View::Board {
public:
    MockBoard() : View::Board() {}
};

TEST(ChessPieceTest, IsWhite) {
    MockBoard board;
    King whiteKing(true, &board);
    King blackKing(false, &board);

    EXPECT_TRUE(whiteKing.isWhite());
    EXPECT_FALSE(blackKing.isWhite());
}

TEST(KingTest, IsValidMove) {
    MockBoard board;
    King whiteKing(true, &board);

    EXPECT_TRUE(whiteKing.isValidMove(3, 3, 4, 3));
    EXPECT_TRUE(whiteKing.isValidMove(3, 3, 3, 4));
    EXPECT_TRUE(whiteKing.isValidMove(3, 3, 4, 4));
    EXPECT_FALSE(whiteKing.isValidMove(3, 3, 5, 5));
}

TEST(QueenTest, IsValidMove) {
    MockBoard board;
    Queen whiteQueen(true, &board);
 
    EXPECT_TRUE(whiteQueen.isValidMove(3, 3, 2, 3));
    EXPECT_TRUE(whiteQueen.isValidMove(3, 3, 4, 3));
    EXPECT_TRUE(whiteQueen.isValidMove(3, 3, 3, 2));
    EXPECT_FALSE(whiteQueen.isValidMove(0, 0, 9, 6));
}

TEST(KnightTest, IsValidMove) {
    MockBoard board;
    Knight whiteKnight(true, board.get());

    EXPECT_TRUE(whiteKnight.isValidMove(4, 4, 3, 6));
    EXPECT_FALSE(whiteKnight.isValidMove(4, 4, 5, 5));
}

TEST(BishopTest, IsValidMove) {
    MockBoard board;
    Bishop whiteBishop(true, board.get());

    EXPECT_TRUE(whiteBishop.isValidMove(5, 4, 2, 7));
    EXPECT_FALSE(whiteBishop.isValidMove(0, 0, 0, 1));
}

TEST(RookTest, IsValidMove) {
    MockBoard board;
    Rook whiteRook(true, &board);

    EXPECT_TRUE(whiteRook.isValidMove(7, 4, 7, 5));
    EXPECT_FALSE(whiteRook.isValidMove(7, 4, 6, 5));
}

TEST(PawnTest, IsValidMove) {
    MockBoard board;
    Pawn whitePawn(true, &board);

    EXPECT_TRUE(whitePawn.isValidMove(6, 0, 5, 0));
    EXPECT_FALSE(whitePawn.isValidMove(6, 0, 7, 4));  
    EXPECT_TRUE(whitePawn.isValidMove(6, 0, 4, 0));
    EXPECT_FALSE(whitePawn.isValidMove(5, 0, 3, 0));
}

TEST(BoardTest, MovePiece) {
    MockBoard board;
    Rook whiteRook(true, &board);
    board.placePiece(3, 3, std::make_shared<Rook>(whiteRook));

    EXPECT_TRUE(board.movePiece(3, 3, 2, 3));
    EXPECT_FALSE(board.movePiece(2, 3, 3, 2));
}

TEST(BoardTest, eat) {
    MockBoard board;
    Rook whiteRook(true, &board);
    Pawn whitePawn(true, &board);
    Pawn blackPawn(false, &board);
    board.placePiece(3, 3, std::make_shared<Rook>(whiteRook));
    board.placePiece(3, 2, std::make_shared<Pawn>(blackPawn));
    board.placePiece(2, 3, std::make_shared<Pawn>(whitePawn));

    EXPECT_FALSE(board.movePiece(3, 3, 2, 3));
    EXPECT_TRUE(board.movePiece(3, 3, 3, 2));
}

TEST(BoardTest, blockedPath) {
    MockBoard board;
    Rook whiteRook(true, &board);
    Pawn whitePawn(true, &board);
    Pawn blackPawn(false, &board);
    board.placePiece(3, 3, std::make_shared<Rook>(whiteRook));
    board.placePiece(3, 2, std::make_shared<Pawn>(blackPawn));
    board.placePiece(2, 3, std::make_shared<Pawn>(whitePawn));

    EXPECT_FALSE(board.movePiece(3, 3, 1, 3));
    EXPECT_FALSE(board.movePiece(3, 3, 3, 1));
}

TEST(BoardTest, knightLeap) {
    MockBoard board;
    Rook whiteRook(true, &board);
    Knight whiteKnight(true, &board);
    board.placePiece(3, 3, std::make_shared<Knight>(whiteKnight));
    board.placePiece(2, 3, std::make_shared<Rook>(whiteRook));

    EXPECT_TRUE(board.movePiece(3, 3, 1, 4));
}

TEST(BoardTest, kingCheck) {
    MockBoard board;
    King whiteKing(true, &board);
    Rook blackRook(false, &board);
    board.placePiece(3, 3, std::make_shared<King>(whiteKing));
    board.placePiece(2, 3, std::make_shared<Rook>(blackRook));

    EXPECT_TRUE(board.isKingInCheck(true));
    board.movePiece(2,3,2,2);
    EXPECT_FALSE(board.isKingInCheck(true));
}

TEST(BoardTest, cantPutKingInCheck) {
    MockBoard board;
    King whiteKing(true, &board);
    Queen whiteQueen(true, &board);
    Rook blackRook(false, &board);
    board.placePiece(3, 3, std::make_shared<King>(whiteKing));
    board.placePiece(2, 3, std::make_shared<Queen>(whiteQueen));
    board.placePiece(1, 3, std::make_shared<Rook>(blackRook));

    EXPECT_TRUE(whiteQueen.isMoveCausingCheck(2,3,2,4));
}

TEST(GameManagerTest, placePiece) {
    MockBoard board;
    GameManager gameManager(board.get());
    gameManager.placePieces();

    ASSERT_EQ(board.pieces[3][3], nullptr);
    ASSERT_NE(board.pieces[0][0], nullptr);
}

TEST(GameManagerTest, createKings) {
    MockBoard board;
    GameManager gameManager(board.get());

    ASSERT_NE(gameManager.createKing(false), nullptr);
}
#endif

