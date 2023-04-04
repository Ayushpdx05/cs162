#ifndef WALL_H
#define WALL_H

#include "MazeLocation.h"


/*********************************************************************
** Function: wall class
** Description: creating the wall clas and object
** Parameters:none
** Pre-Conditions:none
** Post-Conditions: wall exists
*********************************************************************/





class Wall : public MazeLocation {
public:
    Wall(){}// Default constructor
    ~Wall(){}
    char display_char();
    bool is_occupiable() const{
        return false; // Walls cannot be occupied
    }
    char get_display_character() const{
        return '#'; // Display character for walls is always '#'
    }

};

#endif
