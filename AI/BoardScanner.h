
/* 
 * File:   BoardScanner.h
 * Author: axel
 *
 * Created on September 30, 2016, 10:22 PM
 */

#ifndef BOARDSCANNER_H
#define BOARDSCANNER_H

#include <map>
#include "../Game/Board.h"
#include"MoveActions.h"

class BoardScanner {
public:
    typedef std::map<BlockColor, unsigned int> colorCounts;
    typedef std::array<colorCounts, Board::BOARD_HEIGHT> rowColors;
    
    struct VerticalMatch {
        bool found;
        BlockColor color;
        int bottomRow;
        int topRow;
    };
    
    BoardScanner(Board &);

    rowColors countRowColors();
    VerticalMatch findVerticalMatch();
    int findColorCol(BlockColor color, int row);
    
    BlockMoveAction findStackFlatteningMove();
    
    virtual ~BoardScanner();
private:
    Board& _board;

};

#endif /* BOARDSCANNER_H */

