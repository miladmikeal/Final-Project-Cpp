/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Soldier class derived from space. Soldier collects
 * comrades on the board.
****************************************************************/
#include "Soldier.hpp"
#include "Board.hpp"

/****************************************************************
** Description: Constructor for soldier. Initializes pointers to
 * null, type to 'O', and steps to 100.
****************************************************************/
Soldier::Soldier() : Space() {
    top = right = left = bottom = nullptr;
    type = 'O';
    steps = 100;
}

/****************************************************************
** Description: Set steps.
****************************************************************/
void Soldier::setSteps(int s) {
    steps = s;
}

/****************************************************************
** Description: Get steps.
****************************************************************/
int Soldier::getSteps() {
    return steps;
}

/****************************************************************
** Description: Add comrade to comrades vector.
****************************************************************/
void Soldier::addComrade(Space *c) {
    comrades.push_back(c);
}

/****************************************************************
** Description: Return number of comrades in comrade vector.
****************************************************************/
int Soldier::numComrades() {
    return comrades.size();
}