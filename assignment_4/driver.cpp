#include <iostream>
#include "Maze.h"
#include "MazeLocation.h"
#include "MazePerson.h"
#include "Wall.h"
#include "IntrepeidStudent.h"
#include "Instructor.h"
#include "game.h"
#include "OpenSpace.h"
#include "TA.h"
#include <string>
#include <stdlib.h>
using namespace std;


/******************************************************
** Program: assignment4.cpp
** Author: Ayush Singh
** Date: 2/20/2023
** Description: creating a terminal game which represents
a maze 
** Input:none
** Output:a terminal game
******************************************************/



int main(){
   
    int height,width;
    
    game g;

    height = g.get_user_maze_height(); 
    width = g.get_user_maze_width();
    Maze maze(height,width);

   // create the student
    IntrepidStudent student;

    // print the initial state of the maze
    maze.print_maze();

    // start the game loop
    bool game_over = false;
    while (!game_over) {
    // move the student
    maze.move_student();
    maze.move_tas();

    // print the updated maze
    maze.print_maze();

    }    
   
    return 0;
}

