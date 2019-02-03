/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Comrade class header file.
****************************************************************/
#ifndef FINALPROJECT_DRONE_HPP
#define FINALPROJECT_DRONE_HPP

#include "Space.hpp"

class Comrade : public Space {
public:
    Comrade();
    void setSteps(int) override;
    int getSteps() override;
    void addComrade(Space *) override;
    int numComrades() override;
};


#endif //FINALPROJECT_DRONE_HPP
