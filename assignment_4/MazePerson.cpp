#include "MazePerson.h"

/*********************************************************************
** Function:retriving information where the person is on the vector
** Parameters:none
** Pre-Conditions: vector exists
** Post-Conditions:none
*********************************************************************/


std::pair<int, int> MazePerson::get_location() const {
    return std::make_pair(row, col);
}

