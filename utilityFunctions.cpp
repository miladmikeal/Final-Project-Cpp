/****************************************************************
** Program name: Final Project
** Author: Milad Mikeal
** Date: 11/23/18
** Description: getIn function is used for input validation. It
 * prompts the user to enter an int. If non-numeric values,
 * floating point values, or anything else is entered, it prompts
 * the user to re-enter the value. Also includes function to
 * get random nums from array, and a function to have user hit
 * "Enter" to continue.
****************************************************************/
#include "utilityFunctions.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include <cctype>
using std::string;
using std::stoi;
using std::stod;
using std::cout;
using std::cin;
using std::endl;

void getInt(int *pInt, int minVal, int maxVal) {
    // Declare variables
    int x = 1;
    string val;
    bool loop = true;
    // While loop is true
    while(loop) {
        // Input selection
        cout << "Selection: ";
        cin >> val;
        // Exit loop if no failures
        loop = false;
        // Check for non-numeric characters
        x = val.string::find_first_not_of("0123456789");
        if (x >= 0) {
            // Reprompt if non-numeric characters found
            cout << "Invalid! Please enter integer between "
                 << minVal << " and " << maxVal << ": " << endl;
            loop = true;
        }
        // Check if value within range
        if (!loop && (stoi(val) > maxVal || stoi(val) < minVal)) {
            cout << "Invalid! Please enter integer between "
                 << minVal << " and " << maxVal << "." << endl;
            loop = true;
        }
    }
    // Convert to int
    *pInt = stoi(val);
}

void getChar(char *dir) {
    // Declare variable
    char input;
    // Input selection
    cout << "\nSelection: ";
    cin >> input;
    input = tolower(input);
    // Reprompt if invalid
    while (input != 'w' && input != 'a' && input != 'd' && input != 's' && input != 'q' ) {
        cout << "\nInvalid! Please enter " << endl
             << "'w' for up, " << endl
             << "'a' for left, " << endl
             << "'d' for right " << endl
             << "'s' for down, " << endl
             << "or 'q' to quit." << endl;
        cout << "Selection: ";
        cin >> input;
        input = tolower(input);
    }
    // Return value
    *dir = input;
}

void randomNums(int * myArray, int arrSize, int minVal, int maxVal){
    //for loop to generate a complete set of 10 random numbers
    bool dup;
    for (int i = 0; i < arrSize; i++)
    {
        do{
            dup = 0;
            myArray[i] = (rand() % (maxVal - minVal +1)) + minVal;
            for (int j = 0; j < i; j++)
            {
                if (myArray[i] == myArray[j]){
                    dup = 1;
                }
            }
        } while (dup);
    }
}

void enterToContinue(){
    string temp;
    cout << "\n\nPress Enter to Continue...";
    cin.ignore();
    std::getline( cin, temp );
}