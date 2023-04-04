#ifndef INTREPEID_H
#define INTREPEID_H

#include <vector>
#include "MazeLocation.h"
#include "Wall.h"
#include "OpenSpace.h"
#include "MazePerson.h"


/*********************************************************************
** Function: intrepidstudent class
** Description: creating the student object
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:creating the obj
*********************************************************************/



class IntrepidStudent : public MazePerson {
private:
    int programming_skills; // number of programming skills the student is holding

public:
    int num_skills_collected = 0;
    void move(int row_offset, int col_offset) {
    int new_row = this->row + row_offset;
    int new_col = this->col + col_offset;
    this->set_location(new_row, new_col);
}

    char get_move() override { 
        char move;
        cout << "where would you like to move WASD or P" << endl;
        cin >> move;
     } // no move 

    // constructor
    IntrepidStudent() {programming_skills = 0;}

    virtual char get_display_character() const {
        return '@';
    }

    IntrepidStudent(int row, int col) {}

    void increment_programming_skills(int amount) {
    this->programming_skills += amount;
}

    


 
    int get_row() const { return row; }
    int get_col() const { return col; }


    void decrement_programming_skills() {
        programming_skills--;
    }

    int get_programming_skills() {
        return programming_skills;
    }

    void increment_programming_skills(int& skill_level) {
    this->programming_skills += skill_level;
    skill_level = 0;
}



};








#endif