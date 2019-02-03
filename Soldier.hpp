/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Soldier class header file.
****************************************************************/
#ifndef FINALPROJECT_SOLDIER_HPP
#define FINALPROJECT_SOLDIER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Space.hpp"
#include "Comrade.hpp"

class Soldier : public Space {
private:
    int steps;
    std::vector<Space *> comrades;
public:
    Soldier();
    void setSteps(int) override;
    int getSteps() override;
    void addComrade(Space *) override;
    int numComrades() override;
};


#endif //FINALPROJECT_SOLDIER_HPP
