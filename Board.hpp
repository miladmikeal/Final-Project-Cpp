/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Board class header file.
****************************************************************/
#ifndef FINALPROJECT_BOARD_HPP
#define FINALPROJECT_BOARD_HPP

#include <string>
#include "Space.hpp"
#include "Soldier.hpp"

class Board {
private:
    Space ** board;
    int rows, cols, length;
    int soldierLoc;
    int coms;
    void populateBoard(int, int);
    void setBeginLoc();
    void setPointers();
    bool onLeft();
    bool onRight();
    bool onBottom();
    bool onTop();
public:
    void setValues(int, int, int, int);
    int moveSoldier(char);
    void printBoard();
    bool checkWinner();
    int getScore();
    bool stepsRemaining();
    ~Board();
};


#endif //FINALPROJECT_BOARD_HPP
