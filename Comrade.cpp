/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Comrade class derived from space. Comrades are
 * collected by the soldier.
****************************************************************/
#include "Comrade.hpp"

/****************************************************************
** Description:
****************************************************************/
Comrade::Comrade() : Space() {
    type = '$';
}

/****************************************************************
** Description: Does nothing. Method primarily for soldier.
****************************************************************/
void Comrade::setSteps(int) {}

/****************************************************************
** Description: Does nothing. Method primarily for soldier.
****************************************************************/
int Comrade::getSteps() {
    return 0;
}

/****************************************************************
** Description: Does nothing. Method primarily for soldier.
****************************************************************/
void Comrade::addComrade(Space *) {}

/****************************************************************
** Description: Does nothing. Method primarily for soldier.
****************************************************************/
int Comrade::numComrades() {
    return 0;
}