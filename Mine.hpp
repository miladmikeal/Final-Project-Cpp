/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Mine class header file.
****************************************************************/
#ifndef FINALPROJECT_MINE_HPP
#define FINALPROJECT_MINE_HPP

#include "Space.hpp"

class Mine : public Space {
public:
    Mine();
    void setSteps(int) override;
    int getSteps() override;
    void addComrade(Space *) override;
    int numComrades() override;
};


#endif //FINALPROJECT_MINE_HPP
