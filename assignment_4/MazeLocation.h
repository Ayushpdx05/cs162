#ifndef MAZELOCATION_H
#define MAZELOCATION_H

#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
** Function: maze location class
** Description: creating the parent mazelocation class
** Parameters: none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/

class MazeLocation
{
private:
    bool has_student;
    char display_character;
public:
    virtual ~MazeLocation() {};
    virtual bool is_occupiable() const = 0;
    virtual char get_display_character()const = 0;
    virtual char display_char() = 0;
    virtual bool has_skill() const { return false; }

    void set_has_student(bool has_student) {
    this->has_student = has_student;
}

void set_display_character(char display_character) {
    this->display_character = display_character;
}

};

#endif
