/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Reusable menu class. Class can add menu options,
 * display the menu, edit existing menu options, and prompts
 * user for input, using the getInt function for validation.
****************************************************************/
#include <iostream>
#include <limits>
#include <stdlib.h>
#include "Menu.hpp"
#include "utilityFunctions.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

/****************************************************************
** Description: Constructor. Initializes numOptions to 0.
****************************************************************/
Menu::Menu() {
    heading = "Menu:";
    numOptions = 0;
}

Menu::Menu(std::string h) {
    heading = h;
    numOptions = 0;
}

/****************************************************************
** Description: Displays the menu options.
****************************************************************/
void Menu::display(int type) {
    if (type == 0) {
        cout << '\n';
        cout << heading << endl;
        for (int i = 0; i < numOptions; i++) {
            cout << (i + 1) << ". " << options.at(i) << '\n';
        }
    } else {
        cout << '\n';
        cout << heading << endl;
        cout << "w. " << options.at(0) << '\n'
             << "s. " << options.at(1) << '\n'
             << "a. " << options.at(2) << '\n'
             << "d. " << options.at(3) << '\n'
             << "q. " << options.at(4) << '\n';
    }
}

/****************************************************************
** Description: This method adds an option to the menu.
****************************************************************/
void Menu::add(string text) {
    options.push_back(text);
    numOptions++;
}

/****************************************************************
** Description: This method edits the label of an existing
 * option.
****************************************************************/
void Menu::edit(int num, string text) {
    options.at(num-1) = text;
}

/****************************************************************
** Description: This method deletes an option from the menu.
****************************************************************/
void Menu::del(int num) {
    options.erase(options.begin() + (num - 1));
    numOptions--;
}

/****************************************************************
** Description: This method displays the menu, prompts the user
 * for input, and returns the input.
****************************************************************/
int Menu::prompt() {
    display(0);
    return input();
}

/****************************************************************
** Description: This method returns the number of options.
****************************************************************/
int Menu::getNum() {
    return numOptions;
}

/****************************************************************
** Description: This method returns the label of an option.
****************************************************************/
string Menu::getOption(int num) {
    if (num < 1 || num > numOptions) {
        return "ERROR. No menu option.";
    }

    return options.at(num - 1);
}

/****************************************************************
** Description: This method returns the user's selection if it
 * is valid.
****************************************************************/
int Menu::input() {
    if (numOptions > 0) {
        cout << '\n';
        int selection;

        getInt(&selection, 1, numOptions);

        return selection;
    } else {
        cout << "ERROR. No menu options available.\n";
        return -1;
    }
}