#ifndef MAZEPERSON_H
#define MAZEPERSON_H

#include <vector>
#include "MazeLocation.h"
#include "Wall.h"
#include "OpenSpace.h"

/*********************************************************************
** Function: maze person class
** Description:creating maze person parent class
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/

class MazePerson {
protected:
    int row;
    int col;
    
public:
    MazePerson(){} 
    MazePerson(int row, int col) : row(row), col(col) {}
    virtual ~MazePerson() {}

    virtual char get_move() = 0;
    virtual char get_display_character() const = 0;
    
    void set_location(int row, int col) {
        this->row = row;
        this->col = col;
    }
    
    int get_row() const {
        return row;
    }
    
    int get_col() const {
        return col;
    }



    // get the current location of the person
    std::pair<int, int> get_location() const;

    // set the location of the person

    

};




#endif
