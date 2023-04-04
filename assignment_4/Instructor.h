#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <vector>
#include "MazeLocation.h"
#include "Wall.h"
#include "OpenSpace.h"
#include "MazePerson.h"
#include <cstdlib>


/*********************************************************************
** Function:creating instructor which inherets from maze perosn
** Description: creating the instructor object
** Parameters:none
** Pre-Conditions:maze perosn must exist
** Post-Conditions:
*********************************************************************/

class Instructor : public MazePerson {
public:
    Instructor() {}

    char get_move() override {
        // Return no move every time
        return ' ';
    }

    virtual char get_display_character() const {
        return 'I';
    }

};


#endif