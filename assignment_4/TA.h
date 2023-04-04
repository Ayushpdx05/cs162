#ifndef TA_H
#define TA_H

#include <vector>
#include "MazeLocation.h"
#include "Wall.h"
#include "OpenSpace.h"
#include "MazePerson.h"
#include <cstdlib>

/*********************************************************************
** Function:ta class
** Description:creating the ta object
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/

class TA : public MazePerson {
private:
    bool appeased;
    int appease_turns;

public:
    // constructor
    TA() {this->appease_turns = 0;  this->appeased = false;  }


    void set_appeased_turns(int turns) {
    this->appeased = true;
    this->appease_turns = turns;
    }



    char get_move() override { return ' '; } // no move

    virtual char get_display_character() const {
        return 'T';
    }

    bool is_appeased() const {
        return appeased;
    }

    void set_appeased(bool value) {
        appeased = value;
    }

    int get_appease_turns() const {
        return appease_turns;
    }

    void set_appease_turns(int turns) {
        appease_turns = turns;
    }

    void decrement_appease_turns() {
        if (appease_turns > 0) {
            appease_turns--;
        }
        if (appease_turns == 0) {
            appeased = false;
        }
    }
};



#endif