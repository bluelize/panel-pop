/*
 * Game.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: axel
 */

#include "Game.h"

#include "Board.h"

Game::Game() :
		_board(Board()), _paused(false) {
}

void Game::tick() {
	if (!_paused) {
		_board.tick();
	}
}

void Game::inputTogglePause() {
	_paused = !_paused;
}

bool Game::isPaused() {
	return _paused;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

