#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "Maze.h"
#include "MazeLocation.h"
#include "MazePerson.h"
#include "Wall.h"
#include "IntrepeidStudent.h"
#include "Instructor.h"
#include "OpenSpace.h"
#include "TA.h"
using namespace std;

/*********************************************************************
** Function: game class
** Description:creating game logic
** Parameters:none
** Pre-Conditions:none
** Post-Conditions:rest of classes work
*********************************************************************/


class game
{    
public:
int get_user_maze_height();
int get_user_maze_width();
void get_it_to_work();
void retrivieing_information();
void game_setup();
void game_play();
};







#endif