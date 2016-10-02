
/* 
 * File:   AIGameState.cpp
 * Author: axel
 * 
 * Created on September 26, 2016, 11:18 PM
 */

#include "AIGameState.h"

#include "../AI/AIBoardController.h"
#include "../Game/BoardEventHandler.h"
#include "../Game/GameEventHandler.h"
#include "StateManager.h"
#include "../Game/KeyboardController.h"
#include "../Game/VsGame.h"
#include "../Rendering/VsGameRenderer.h"

AIGameState::AIGameState() {
    _game = new VsGame(new GameEventHandler());

    _gameRenderer = new VsGameRenderer((VsGame&) * _game);

    _game->getBoard(0).setEventHandler(new BoardEventHandler(*_gameRenderer, 0));
    _game->getBoard(1).setEventHandler(new BoardEventHandler(*_gameRenderer, 1));

    //_playerBoardController = new KeyboardController(_game->getBoard(0), StateManager::getInstance().getP1keys());
    _playerBoardController = new AIBoardController(_game->getBoard(0));
    
    _opponentBoardcontollers.push_back(new AIBoardController(_game->getBoard(1)));
}


