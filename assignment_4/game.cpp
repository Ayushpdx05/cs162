#include "game.h"
#include <iostream>
#include <cctype>
#include <string>
#include <limits>
using namespace std;


/*********************************************************************
** Function:get user maze heigh and width
** Description:getting the width and height of user maze
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:maze exists
*********************************************************************/


int game::get_user_maze_height() {
    int height;
    do {
        cout << "Please enter the height of the maze (must be greater than or equal to 5): ";
        cin >> height;

        if (cin.fail()) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignore the rest of the input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

    } while (height < 5);
    return height;
}

int game::get_user_maze_width() {
    int width;
    do {
        cout << "Please enter the width of the maze (must be greater than or equal to 5): ";
        cin >> width;

        if (cin.fail()) {
            cin.clear();  // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignore the rest of the input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

    } while (width < 5);
    return width;
}

