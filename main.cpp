/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: This program simulates a soldier (O) navigating
 * through a field of randomly placed hidden mines (*) and
 * gathering comrades before getting to a safe zone. The user
 * controls the movement of the soldier, who has 100 steps to
 * gather his comrades and get to the safe zone. Landing on a
 * mine will knock the soldier back to the beginning and deduct
 * 10 steps, gathering a comrade will gain the solider 5 steps,
 * every other movement deducts 1 step.
****************************************************************/
#include <iostream>
#include <ctime>
#include "Board.hpp"
#include "Menu.hpp"
#include "utilityFunctions.hpp"
using std::cout;
using std::endl;

int main() {
    // Seed rand
    unsigned int sval;
    time_t t;
    sval = (unsigned) time(&t);
    srand(sval);
    // Declare variables
    int selection, diff, run = 1;
    char moveChoice;
    // Create Main menu
    Menu main("Main Menu:");
    // Add menu options
    main.add("Start game");
    main.add("Quit");
    // Create move menu
    Menu move("Which direction would you like to move:");
    // Add move menu options
    move.add("Up");
    move.add("Down");
    move.add("Left");
    move.add("Right");
    move.add("Quit");
    // Create difficulty menu
    Menu difficulty("Select difficulty:");
    // Add difficulty menu options
    difficulty.add("Easy - 8% mines, 5 comrades");
    difficulty.add("Medium - 9.3% mines, 6 comrades");
    difficulty.add("Hard - 10.6% mines, 7 comrades");
    // Create playAgain menu
    Menu playAgain("Would you like to play again?");
    playAgain.add("Yes");
    playAgain.add("No");
    // Prompt main menu
    selection = main.prompt();
    // If user selects to start game
    while (run) {
        if (selection == 2) {
            return 0;
        } else {
            // Display mission objectives
            cout << "\nWelcome soldier! " << endl
                 << "You have been tasked with Operation Purple Turtle! " << endl
                 << "The objective is simple. Gather your comrades ($) " << endl
                 << "and get to the safe zone. You have 100 steps to do so. " << endl
                 << "Be aware though, the enemies have planted land mines " << endl
                 << "in random locations across the field. If you hit one, " << endl
                 << "you will lose 10 steps, and start back at the beginning." << endl
                 << "Gather a comrade and you will gain an additional 5 steps." << endl;
            // Enter to continue
            enterToContinue();
            Board board;
            // Prompt user for difficulty
            diff = difficulty.prompt();
            if (diff == 1) {
                // Create easy board
                board.setValues(15, 25, 30, 5);
            } else if (diff == 2) {
                // Create medium board
                board.setValues(15, 25, 40, 6);
            } else if (diff == 3) {
                // Create hard board
                board.setValues(15, 25, 50, 7);
            }
            // Print initial status of board
            board.printBoard();
            // Loop until out of steps / won game
            while (board.stepsRemaining() && !board.checkWinner()) {
                // Prompt direction choice
                move.display(1);
                getChar(&moveChoice);

                switch (moveChoice) {
                    // up
                    case 'w':
                        board.moveSoldier('u');
                        board.checkWinner();
                        board.stepsRemaining();
                        break;
                    // down
                    case 's':
                        board.moveSoldier('d');
                        board.checkWinner();
                        board.stepsRemaining();
                        break;
                    // left
                    case 'a':
                        board.moveSoldier('l');
                        board.checkWinner();
                        board.stepsRemaining();
                        break;
                    // right
                    case 'd':
                        board.moveSoldier('r');
                        board.checkWinner();
                        board.stepsRemaining();
                        break;
                    // Otherwise quit game
                    case 'q':
                        cout << "\nYou have let your comrades down!" << endl;
                        return 0;
                }
            }
            // If winner
            if (board.checkWinner()) {
                // Winner message + score
                cout << "\nMission Success!" << endl
                     << "Your country will not forget this!" << endl
                     << "Score: " << board.getScore() << endl;
            // If loser
            } else {
                // Loser message
                cout << "\nMission Failed!" << endl
                     << "You have failed your comrades." << endl
                     << "You have failed your country." << endl
                     << "Try Again!" << endl;
            }
        }
        // Prompt playAgain menu
        run = playAgain.prompt();
        if (run == 2) {
            return 0;
        }
    }
}