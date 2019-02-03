/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Mine class derived from space. Mine causes
 * soldier to lose 10 steps and start back at the beginning.
****************************************************************/
#include "Mine.hpp"

/****************************************************************
** Description: Constructor. Initializes type to '*'.
****************************************************************/
Mine::Mine() : Space() {
    type = '*';
}

/****************************************************************
** Description: Does nothing. Method primarily for soldier.
****************************************************************/
void Mine::setSteps(int) {}

/****************************************************************
** Description: Does nothing. Method primarily for soldier.
****************************************************************/
int Mine::getSteps() {
    return 0;
}

/****************************************************************
** Description: Does nothing. Method primarily for soldier.
****************************************************************/
void Mine::addComrade(Space *) {}

/****************************************************************
** Description: Does nothing. Method primarily for soldier.
****************************************************************/
int Mine::numComrades() {
    return 0;
}