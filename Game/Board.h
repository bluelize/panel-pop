/*
 * Board.h
 *
 *  Created on: Aug 16, 2015
 *      Author: axel
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Block.h"
#include "GarbageBlock.h"

enum Direction {
	UP, RIGHT, DOWN, LEFT
};

enum TileType {
			AIR, BLOCK, GARBAGE
};

class Board {
public:

	struct Tile {
		Tile();
		TileType type;
		Block b;
		GarbageBlock* g;
	};

//TODO: Use getters!!
	Board();
	Tile _tiles[24][6];
	Tile _bufferRow[6];
	virtual ~Board();
	int _cursorX, _cursorY;
	int _tickMatched; //how many blocks got matched this tick
	int _stackOffset;
	int _stackRaiseTicks;
	int _stackRaiseTimer;
	bool _stackRaiseForced;
	bool _activeBlocks;
	int _chainCounter;
	bool _tickChain; //true if a chain has occurred during the tick
	int _tickChainRow;
	int _tickChainCol;
	int _tickMatchRow;
	int _tickMatchCol;
	void tick();
	void inputMoveCursor(Direction);
	void inputSwapBlocks();
	void inputForceStackRaise();
	static const int BASE_EXPLOSION_TICKS = 61;
	static const int ADD_EXPL_TICKS = 9; //the total explosion time for a combo is 61 + 9 * n, where n is the  number of blocks
	static const int SWAP_DELAY = 3;
	static const int BOARD_HEIGHT = 24;
	static const int BOARD_WIDTH = 6;
	enum BoardState {
		RUNNING, PAUSED, GAME_OVER
	} _state;
private:
	void initTick();
	void initializeTiles();
	void fillRandom();
	void fillBufferRow();
	bool activeBlocks();
	void matchBlocks();
	void handleMatchedBlocks();
	void handleBlockTimers();
	void swapBlocks(int, int);
	void deleteBlock(Tile&);
	void setChain(int, int);
	void handleFalling();
	void raiseStack();
	bool matchTiles(int, int, int, int);
	bool blockCanFall(int, int);
	bool swappable(int, int);

	static const int FLOAT_TICKS = 12;
};

#endif /* BOARD_H_ */
