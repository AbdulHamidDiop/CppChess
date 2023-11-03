#ifndef PIECE_PLACEMENT_H
#define PIECE_PLACEMENT_H
#pragma once
#include "echequier.h"
#include "chessPiece.h"
#include "king.h"
#include "queen.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "pawn.h"
#include <QPushButton>
#include <memory>

class GameManager {

public:
	GameManager(View::Board* board);
	std::shared_ptr<Model::King> createKing(bool bOw);
	void placePieces();

	std::unique_ptr<QWidget> startWindow(QWidget& selectionWindow);
	std::unique_ptr<QWidget> selectionWindow();

private:
	View::Board* board_;
	int configuration = 1;
};
#endif 

