/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: Simulates the board of the game. Sets values,
 * populates the board, moves the soldier, prints the board,
 * sets pointers, checks winner, and returns steps of soldier.
****************************************************************/
#include <iostream>
#include "Board.hpp"
#include "Soldier.hpp"
#include "Comrade.hpp"
#include "Mine.hpp"
#include "utilityFunctions.hpp"
using std::cout;
using std::endl;

/****************************************************************
** Description:Constructor. Initializes member variables,
 * dynamically allocates board, and calls populateBoard method.
****************************************************************/
void Board::setValues(int r, int c, int mines, int comrades) {
    rows = r;
    cols = c;
    coms = comrades;
    length = rows * cols;
    // Dynamically  allocate board of Space pointers
    board = new Space*[length];
    // Set Space pointers to null
    for (int i = 0; i < length; i++) {
        board[i] = nullptr;
    }
    // Set soldierLoc to middle of bottom row
    soldierLoc = (rows-1) * cols + (cols/2);
    // Place mines in random spots
    populateBoard(mines, comrades);
}

/****************************************************************
** Description: Populates the board with necessary mines,
 * comrades, and one soldier.
****************************************************************/
void Board::populateBoard(int mines, int comrades) {
    // Get total num of objects
    int objects = mines + comrades;
    // Put objects into array
    int* objectLocs = new int[objects];
    // Initiate array w/ dummy values
    for (int i = 0; i < objects; i++) {
        objectLocs[i] = 0;
    }
    // Get random nums for location of mines & comrades
    randomNums(objectLocs, objects, (cols*2), (length-(cols*2)-1)); // No mines on first 2 rows
    // Place mines
    for (int i = 0; i < mines; i++) {
        if (board[objectLocs[i]]) {
            delete board[objectLocs[i]];
        }
        board[objectLocs[i]] = new Mine();
    }
    // Place comrades
    for (int i = mines; i < objects; i++) {
        if (board[objectLocs[i]]) {
            delete board[objectLocs[i]];
        }
        board[objectLocs[i]] = new Comrade();
    }
    // Delete objectLocs array
    delete [] objectLocs;
    // Start soldier in center of bottom row
    board[soldierLoc] = new Soldier();
    // Set pointers
    setPointers();
}



/****************************************************************
** Description: Moves the soldier in the direction specified by
 * the user, adjusts necessary variables, and print the board.
****************************************************************/
int Board::moveSoldier(char dir) {
    switch (dir) {
        // If up
        case 'u':
            // If space is null
            if (board[soldierLoc - cols] == nullptr) {
                // Move soldier
                board[soldierLoc - cols] = board[soldierLoc];
                // Set previous space to null
                board[soldierLoc] = nullptr;
                // Adjust soldierLoc
                soldierLoc -= cols;
                // Adjust pointers
                setPointers();
                // Adjust steps
                board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() - 1);
            } else {
                // If space occupied by mine
                if (board[soldierLoc - cols]->getType() == '*') {
                    cout << "\nYou landed on a mine!" << endl
                         << "Reset and finish your mission!" << endl;
                    // Delete mine
                    delete board[soldierLoc - cols];
                    // Set space to null
                    board[soldierLoc - cols] = nullptr;
                    // Move soldier back to beginning
                    setBeginLoc();
                    // Adjust steps
                    board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() - 10);
                // If space occupied by comrade
                } else if (board[soldierLoc - cols]->getType() == '$') {
                    // Add comrade to comrades vector
                    board[soldierLoc]->addComrade(board[soldierLoc - cols]);
                    // Delete the comrade from space
                    delete board[soldierLoc - cols];
                    // Move soldier there
                    board[soldierLoc - cols] = board[soldierLoc];
                    // Set previous space to null
                    board[soldierLoc] = nullptr;
                    // Adjust soldierLoc
                    soldierLoc -= cols;
                    // Adjust pointers
                    setPointers();
                    // Adjust steps
                    board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() + 5);
                } else {
                    cout << board[soldierLoc - cols]->getType();
                }
            }
            break;
        // If left
        case 'l':
            // Check if up against wall
            if (onLeft()) {
                cout << "Can't move that direction." << endl;
                return -1;
            }
            // If space is null
            if (board[soldierLoc - 1] == nullptr) {
                // Move soldier
                board[soldierLoc - 1] = board[soldierLoc];
                // Set previous space to null
                board[soldierLoc] = nullptr;
                // Adjust soldierLoc
                soldierLoc -= 1;
                // Adjust pointers
                setPointers();
                // Adjust steps
                board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() - 1);
            } else {
                // If space is occupied by mine
                if (board[soldierLoc - 1]->getType() == '*') {
                    cout << "\nYou landed on a mine!" << endl
                          << "Reset and finish your mission!" << endl;
                    // Delete mine
                    delete board[soldierLoc - 1];
                    // Set space to null
                    board[soldierLoc - 1] = nullptr;
                    // Move soldier back to beginning
                    setBeginLoc();
                    // Adjust steps
                    board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() - 10);
                // If space is occupied by comrade
                } else if (board[soldierLoc - 1]->getType() == '$') {
                    // Add comrade to comrades vector
                    board[soldierLoc]->addComrade(board[soldierLoc - 1]);
                    // Delete the comrade from space
                    delete board[soldierLoc - 1];
                    // Move soldier
                    board[soldierLoc - 1] = board[soldierLoc];
                    // Set previous space to null
                    board[soldierLoc] = nullptr;
                    // Adjust soldierLoc
                    soldierLoc -= 1;
                    // Adjust pointers
                    setPointers();
                    // Adjust steps
                    board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() + 5);
                } else {
                    cout << board[soldierLoc - 1]->getType();
                }
            }
            break;
        // If right
        case 'r':
            // Check if up against wall
            if (onRight()) {
                cout << "Can't move that direction." << endl;
                return -1;
            }
            // If space is null
            if (board[soldierLoc  + 1] == nullptr) {
                // Move soldier
                board[soldierLoc + 1] = board[soldierLoc];
                // Set previous space to null
                board[soldierLoc] = nullptr;
                // Adjust soldierLoc
                soldierLoc += 1;
                // Adjust pointers
                setPointers();
                // Adjust steps
                board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() - 1);
            } else {
                // If space is occupied by mine
                if (board[soldierLoc + 1]->getType() == '*') {
                    cout << "\nYou landed on a mine!" << endl
                         << "Reset and finish your mission!" << endl;
                    // Delete mine
                    delete board[soldierLoc + 1];
                    // Set space to null
                    board[soldierLoc + 1] = nullptr;
                    // Move soldier back to beginning
                    setBeginLoc();
                    // Adjust steps
                    board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() - 10);
                // If space is occupied by comrade
                } else if (board[soldierLoc + 1]->getType() == '$') {
                    // Add comrade to comrades vector
                    board[soldierLoc]->addComrade(board[soldierLoc + 1]);
                    // Delete comrade from space
                    delete board[soldierLoc + 1];
                    // Move soldier
                    board[soldierLoc + 1] = board[soldierLoc];
                    // Set previous space to null
                    board[soldierLoc] = nullptr;
                    // Adjust soldierLoc
                    soldierLoc += 1;
                    // Adjust pointers
                    setPointers();
                    // Adjust steps
                    board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() + 5);
                } else {
                    cout << board[soldierLoc + 1]->getType();
                }
            }
            break;
        // If down
        case 'd':
            // Check if up against wall
            if (onBottom()) {
                cout << "Can't move that direction." << endl;
                return -1;
            }
            // If space is null
            if (board[soldierLoc + cols] == nullptr) {
                // Move soldier
                board[soldierLoc + cols] = board[soldierLoc];
                // Set previous space to null
                board[soldierLoc] = nullptr;
                // Adjust soldierLoc
                soldierLoc += cols;
                // Adjust pointers
                setPointers();
                // Adjust steps
                board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() - 1);
            } else {
                // If space is occupied by mine
                if (board[soldierLoc + cols]->getType() == '*') {
                    cout << "\nYou landed on a mine!" << endl
                         << "Reset and finish your mission!" << endl;
                    // Delete mine
                    delete board[soldierLoc + cols];
                    // Set space to null
                    board[soldierLoc + cols] = nullptr;
                    // Move soldier back to beginning
                    setBeginLoc();
                    // Adjust steps
                    board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() - 10);
                // If space is occupied by comrade
                } else if (board[soldierLoc + cols]->getType() == '$') {
                    // Add comrade to comrades vector
                    board[soldierLoc]->addComrade(board[soldierLoc + cols]);
                    // Delete comrade from space
                    delete board[soldierLoc + cols];
                    // Move soldier to space
                    board[soldierLoc + cols] = board[soldierLoc];
                    // Set previous space to null
                    board[soldierLoc] = nullptr;
                    // Adjust soldierLoc
                    soldierLoc += cols;
                    // Adjust pointers
                    setPointers();
                    // Adjust steps
                    board[soldierLoc]->setSteps(board[soldierLoc]->getSteps() + 5);
                } else {
                    cout << board[soldierLoc + cols]->getType();
                }
            }
            break;
    }
    // If get to top and comrades not gathered
    if (onTop() && board[soldierLoc]->numComrades() != coms) {
        // Set back to begin location
        cout << "Gather all your comrades first!" << endl;
        setBeginLoc();
    }
    // Print board at current state
    printBoard();
    // Display steps remaining
    cout << "Steps Remaining: " <<  board[soldierLoc]->getSteps() << endl;
    return 0;
}

/****************************************************************
** Description: Prints the board in its current state.
****************************************************************/
void Board::printBoard() {
    // Safe zone
    cout << endl;
    cout << '|';
    cout << "        Safe Zone        ";
    cout << '|';
    cout << endl;
    for (int i = 0; i < 1; i++) {
        cout << '|';
        for (int j = 0; j < cols; j++) {
            cout << '_';
        }
        cout << '|' << endl;
    }
    for (int i = 1; i < rows; i++) {
        // Left wall
        cout << '|';
        for (int j = 0; j < cols; j++) {
            if (board[i * cols + j]) {
                if (board[i * cols + j]->getType() == '*') {
                    // Remember to change to space after debugging
                    cout << " ";
                    //cout << board[i * cols +j]->getType();
                } else {
                    cout << board[i * cols + j]->getType();
                }
            } else {
                cout << " ";
            }
        }
        // Right wall
        cout << '|' << endl;
    }
    // Bottom wall
    for (int i = 0; i < cols + 2; i++) {
        cout << '-';
    }
    cout << endl;
}

/****************************************************************
** Description: Moves the soldier back to starting location and
 * adjusts pointers.
****************************************************************/
void Board::setBeginLoc() {
    int tmp = soldierLoc;
    soldierLoc = (rows-1) * cols + (cols/2);
    board[soldierLoc] = board[tmp];
    board[tmp] = nullptr;
    // Set directional pointers
    setPointers();
}

/****************************************************************
** Description: Set directional pointers.
****************************************************************/
void Board::setPointers() {
    // If on top wall
    if (onTop()) {
        // Set top pointer to null
        board[soldierLoc]->setTop(nullptr);
    // Otherwise
    } else {
        // Set to space on top
        board[soldierLoc]->setTop(board[soldierLoc - cols]);
    }
    // If up against left wall
    if (onLeft()) {
        // Set left pointer to null
        board[soldierLoc]->setLeft(nullptr);
    // Otherwise
    } else {
        // Set to space on left
        board[soldierLoc]->setLeft(board[soldierLoc - 1]);
    }
    // If up against right wall
    if (onRight()) {
        // Set right pointer to null
        board[soldierLoc]->setRight(nullptr);
    // Otherwise
    } else {
        // Set to space on right
        board[soldierLoc]->setRight(board[soldierLoc + 1]);
    }
    // If up against bottom wall
    if (onBottom()) {
        // Set bottom pointer to null
        board[soldierLoc]->setBottom(nullptr);
    // Otherwise
    } else {
        // Set to space below
        board[soldierLoc]->setBottom(board[soldierLoc + cols]);
    }
}

/****************************************************************
** Description: Checks to see if up against left wall.
****************************************************************/
bool Board::onLeft() {
    return soldierLoc % 25 == 0;
}

/****************************************************************
** Description: Checks to see if up against right wall.
****************************************************************/
bool Board::onRight() {
    return soldierLoc % 25 == 24;
}

/****************************************************************
** Description: Checks to see if up against bottom wall.
****************************************************************/
bool Board::onBottom() {
    return (soldierLoc >= 350 && soldierLoc < 375);
}

/****************************************************************
** Description: Checks to see if up against top.
****************************************************************/
bool Board::onTop() {
    return (soldierLoc >= 0 && soldierLoc < 25);
}

/****************************************************************
** Description: Checks to see if soldier has steps remaining.
****************************************************************/
bool Board::stepsRemaining() {
    return board[soldierLoc]->getSteps() > 0;
}

/****************************************************************
** Description: Boolean to check if player has won.
****************************************************************/
bool Board::checkWinner() {
    return board[soldierLoc]->numComrades() == coms && onTop();
}

/****************************************************************
** Description: Returns the score (steps remaining).
****************************************************************/
int Board::getScore() {
    return board[soldierLoc]->getSteps();
}

/****************************************************************
** Description: Destructor. Frees memory.
****************************************************************/
Board::~Board() {
    for (int i = 0; i < length; i++) {
        if (board[i]) {
            delete board[i];
        }
    }
    delete [] board;
}

