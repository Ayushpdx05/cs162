#ifndef OPENSPACE_H
#define OPENSPACE_H

#include <iostream>
#include "MazeLocation.h"
#include "Wall.h"



/*********************************************************************
** Function:open space class
** Description: creating the open space object
** Parameters:none
** Pre-Conditions:mazelocation exists
** Post-Conditions:none
*********************************************************************/




class OpenSpace : public MazeLocation {
private:
    bool student;
    bool ta;
    bool instructor;
    bool skill;
    char display_character_;
    
public:
    //creating an open space
    OpenSpace() : student(false), ta(false), instructor(false), skill(false), display_character_('-') {} 
    
    //deciding wheter space is occupiable and returing character if it is not 
    bool is_occupiable() const override { return true; }
    char get_display_character() const override { return display_character_; }

    
    char display_char() override { return '-'; }

    
    
    
};


class SkillLocation : public MazeLocation {
private:
    bool contains_skill;
public:
    SkillLocation() : contains_skill(true) {}
    ~SkillLocation(){}
    bool is_occupiable() const override { return true; }
    char get_display_character() const override { return contains_skill ? 'p' : '-'; }
    char display_char() override { return contains_skill ? '-' : ' '; }
    void remove_skill() {
        contains_skill = false;
    }
    bool has_skill() const override {
        return contains_skill;
    }
};













#endif