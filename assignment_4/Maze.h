#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "MazeLocation.h"
#include "Wall.h"
#include "OpenSpace.h"
#include "IntrepeidStudent.h"
#include "TA.h"
#include "Instructor.h"

/*********************************************************************
** Function: maze class
** Description:creaitng maze object and vectors
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:none
*********************************************************************/

class Maze {
public:
   
    Maze(int height, int width);
    ~Maze(){}
    MazeLocation* get_location(int row, int col);
    MazePerson* get_person(int row, int col);
    void print_maze();
    void move_student();
    void move_maze_person(MazePerson* person, char move);
    void move_student(int row_offset, int col_offset); 
    void set_location(MazePerson* person, int row, int col);
    void update_person_location(int old_row, int old_col, int new_row, int new_col);
    bool is_programming_skill(int row, int col) const;
    void remove_skill_at(int row, int col);
    bool has_skill(int row, int col);
    int get_num_skills_remaining();
    void move_tas();
private:
    int height;
    int width;
    std::vector<std::vector<MazeLocation*> > locations;
    std::vector<std::vector<MazePerson*> > people;
    std::pair<int, int> student_location;
    int num_skills_remaining;
    int num_skills_collected = 0;
};


#endif