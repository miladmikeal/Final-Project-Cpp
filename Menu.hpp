/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Menu class header file.
****************************************************************/
#ifndef FINALPROJECT_MENU_HPP
#define FINALPROJECT_MENU_HPP


#include <vector>
#include <string>
#include <iostream>
#include <math.h>

class Menu {
private:
    std::string heading;
    int numOptions;
    std::vector<std::string> options;
    int input();
public:
    Menu();
    Menu(std::string);
    void display(int);
    void add(std::string);
    void edit(int, std::string);
    void del(int);
    int prompt();
    int getNum();
    std::string getOption(int);
};


#endif //FINALPROJECT_MENU_HPP
