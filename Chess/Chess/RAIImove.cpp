#include "RAIImove.h"

RaiiMove::RaiiMove(View::Board& board,int fromRow, int fromCol, int toRow, int toCol): 
	board(board),
	startRow(fromRow), startCol(fromCol),
	testRow(toRow), testCol(toCol) {}

void RaiiMove::move() {
	board.movePiece(startRow, startCol, testRow, testCol);
}

RaiiMove::~RaiiMove() {
	board.movePiece(testRow, testCol, startRow,startCol);
}


