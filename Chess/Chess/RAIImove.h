#pragma once
#pragma once
#include "echequier.h"

class RaiiMove
{
public:
	RaiiMove(View::Board& board, int fromRow, int fromCol, int toRow, int toCol);
	void move();
	~RaiiMove();
	int startRow, startCol, testRow, testCol;

private:
	View::Board& board;
};
