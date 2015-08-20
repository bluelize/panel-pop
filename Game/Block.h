/*
 * Block.h
 *
 *  Created on: Aug 16, 2015
 *      Author: axel
 */

#ifndef BLOCK_H_
#define BLOCK_H_

enum BlockState {
	NORMAL, FLOATING, MATCHED, EXPLODING
};

enum BlockColor {
	PURPLE, YELLOW, RED, CYAN, GREEN,
	COUNT
};

class Block {
public:
	Block();
	virtual ~Block();

	BlockState _state;
	BlockColor _color;

	int _explosionTicks;
	int _explosionAnimTicks;
	int _explosionTimer;
	bool _animBlinkState;
};

#endif /* BLOCK_H_ */