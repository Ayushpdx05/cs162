#include "Maze.h"
#include <cstdlib>
#include <typeinfo>



/******************************************************
** Program: assignment4.cpp
** Author: Your Name
** Date: 2/20/2023
** Description: to simulate a terminal game
** Input:none
** Output: a terminal game
******************************************************/






/*********************************************************************
** Function: maze constructor
** Description: creating the objects inside of the maze
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: vector will be created
*********************************************************************/

Maze::Maze(int height, int width) {
    this->height = height;
    this->width = width;


    this->student_location = std::make_pair(0, 0);


    // initialize the locations and people vectors
    for (int i = 0; i < height; ++i) {
        std::vector<MazeLocation*> row_locations;
        std::vector<MazePerson*> row_people;
        for (int j = 0; j < width; ++j) {
            row_locations.push_back(new OpenSpace());
            row_people.push_back(NULL);
        }
        this->locations.push_back(row_locations);
        this->people.push_back(row_people);
    }

    // randomly place the walls
    for (int i = 0; i < 4; ++i) {
        int row, col;
        do {
            row = rand() % height;
            col = rand() % width;
        } while (dynamic_cast<Wall*>(this->locations[row][col]) != NULL);
        delete this->locations[row][col];
        this->locations[row][col] = new Wall();
    }

    // place 3 TAs
    for (int i = 0; i < 3; ++i) {
    int ta_row, ta_col;
    do {
        ta_row = rand() % height;
        ta_col = rand() % width;
    } while (this->locations[ta_row][ta_col]->is_occupiable() == false || this->people[ta_row][ta_col] != NULL);
    this->people[ta_row][ta_col] = new TA();
    }
 
    
    // place the instructor
    int instructor_row, instructor_col;
    do {
        instructor_row = rand() % height;
        instructor_col = rand() % width;
    } while (this->locations[instructor_row][instructor_col]->is_occupiable() == false || this->people[instructor_row][instructor_col] != NULL);
    this->people[instructor_row][instructor_col] = new Instructor();
    
    // place the student
    int student_row, student_col;
    do {
        student_row = rand() % height;
        student_col = rand() % width;
        student_location = std::make_pair(student_row, student_col);
    } while (this->locations[student_row][student_col]->is_occupiable() == false || this->people[student_row][student_col] != NULL);
    this->people[student_row][student_col] = new IntrepidStudent();

    // Place the programming skills randomly in the maze
    int skills_placed = 0;
while (skills_placed < 6) {
    int skill_row, skill_col;
    do {
        skill_row = rand() % height;
        skill_col = rand() % width;
    } while (!this->locations[skill_row][skill_col]->is_occupiable());

    delete this->locations[skill_row][skill_col];
    this->locations[skill_row][skill_col] = new SkillLocation();
    ++skills_placed;
}
}



bool Maze::has_skill(int row, int col) {
    return this->locations[row][col]->display_char() == 'p';
}

int Maze::get_num_skills_remaining() {
    return this->num_skills_remaining;
}

/*********************************************************************
** Function: move_tas
** Description: creating the logic behind the tas moving in the game
** Parameters: none
** Pre-Conditions:none
** Post-Conditions: ta object exists in the game
*********************************************************************/


void Maze::move_tas() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (people[i][j] != NULL && typeid(*people[i][j]) == typeid(TA)) {
                // Generate a random direction for the TA
                int direction = rand() % 4; // 0 = up, 1 = left, 2 = down, 3 = right
                int new_i = i, new_j = j;
                if (direction == 0) {
                    new_i--; // move up
                } else if (direction == 1) {
                    new_j--; // move left
                } else if (direction == 2) {
                    new_i++; // move down
                } else {
                    new_j++; // move right
                }
                // Check if the new location is occupiable and not already occupied by another TA
                if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width
                    && locations[new_i][new_j]->is_occupiable() && people[new_i][new_j] == NULL) {
                    // Move the TA to the new location
                    people[new_i][new_j] = people[i][j];
                    people[i][j] = NULL;
                }
            }
        }
    }
}




/*********************************************************************
** Function: move_student
** Description: randomly move student depending on what direction they choose 
** Parameters: none
** Pre-Conditions:none
** Post-Conditions: student object exists
*********************************************************************/


void Maze::move_student() {
    // Get the current position of the student
    int current_row = this->student_location.first;
    int current_col = this->student_location.second;

    // Get the new position based on user input
    char move_direction;
    cout << "Enter direction to move (WASD): ";
    cin >> move_direction;

    // Move student based on direction input
    // Move student based on direction input
switch (move_direction) {
    case 'W':
        current_row--;
        break;
    case 'A':
        current_col--;
        break;
    case 'S':
        current_row++;
        break;
    case 'D':
        current_col++;
        break;
    case 'P': // uppercase letter 'P'
       if (this->num_skills_collected == 0) {
            cout << "Sorry, you don't have any skills to use for appeasing the TA." << endl;
            return;
        } else {
            // Set all TA objects to appeased for 10 turns
            for (int i = 0; i < this->height; i++) {
                for (int j = 0; j < this->width; j++) {
                    if (this->people[i][j] != NULL && typeid(*this->people[i][j]) == typeid(TA)) {
                        TA* ta = dynamic_cast<TA*>(this->people[i][j]);
                        ta->set_appease_turns(10);
                    }
                }
            }
            cout << "You have appeased all TAs for 10 turns!" << endl;
            this->num_skills_collected--;
        }
        return;
    default:
        cout << "Invalid input. Please enter a direction (WASD). or p to appease " << endl;
        break;
}


    if (this->locations[current_row][current_col] != NULL) {
    cout << "Invalid move: the cell at (" << current_row << ", " << current_col << ") is already occupied!" << endl;
}

    // Check if the new position is valid
    if (current_row < 0 || current_row >= this->height || current_col < 0 || current_col >= this->width) {
        // New position is outside the maze
        cout << "You cannot move outside the maze." << endl;
        return;
    }
    MazeLocation* new_location = this->locations[current_row][current_col];
    if (!new_location->is_occupiable()) {
        // New position is not occupiable
        cout << "You cannot move into a wall." << endl;
        return;
    }
    



    // Check if the new location has a TA
    if (people[current_row][current_col] != NULL && typeid(*people[current_row][current_col]) == typeid(TA)) {
    TA* ta = dynamic_cast<TA*>(people[current_row][current_col]);
    if (ta != NULL && !ta->is_appeased()) {
        bool adjacent_to_ta = false;
        for (int i = -2; i <= 2; ++i) {
            for (int j = -2; j <= 2; ++j) {
                int row = current_row + i;
                int col = current_col + j;
                if (row < 0 || row >= this->height || col < 0 || col >= this->width) {
                    continue; // skip out-of-bounds locations
                }
                if (people[row][col] != NULL && typeid(*people[row][col]) == typeid(IntrepidStudent)) {
                    // Check if the student is adjacent to or in the same cell as the TA
                    if (abs(row - current_row) <= 1 && abs(col - current_col) <= 1) {
                        adjacent_to_ta = true;
                        break;
                    }
                }
            }
            if (adjacent_to_ta) {
                cout << "Sorry, you lost the game because you are adjacent to or in the same box as a TA." << endl;
                exit(-1);
                break;
            }
        }
    }
}





    if (people[current_row][current_col] != NULL && typeid(*people[current_row][current_col]) == typeid(Instructor))
    {
       cout << "You have encountered instructor." << endl;
       if (this->num_skills_collected >= 3)
       {
        cout << "well done you have satisfied the instructor" << endl;
        exit(-1);
       }
       else{
        cout << "sorry you dont have enough skills to satisfy the instructor" << endl;
        exit(-1);
       }
       return; 
    } 

    // Check if the current location contains a programming skill
    if (locations[current_row][current_col] != NULL && typeid(*locations[current_row][current_col]) == typeid(SkillLocation)) {
    // Output a message to the console
    cout << "You have picked up a skill!" << endl;

    // Remove the skill from the SkillLocation object
    dynamic_cast<SkillLocation*>(locations[current_row][current_col])->remove_skill();

    cout << "you have collected " << num_skills_collected + 1 << " skills " << endl;

    // Increment the number of skills collected by the student
    ++num_skills_collected;
 
    }
 
    
    

    // Move the student to the new position 
    this->people[current_row][current_col] = this->people[this->student_location.first][this->student_location.second];
    this->people[this->student_location.first][this->student_location.second] = NULL;
    this->student_location.first = current_row;
    this->student_location.second = current_col;

   
}











void Maze::set_location(MazePerson* person, int row, int col) {
    int old_row = person->get_location().first;
    int old_col = person->get_location().second;
    this->people[old_row][old_col] = NULL;
    this->people[row][col] = person;
    person->set_location(row, col);
}



void Maze::move_maze_person(MazePerson* person, char move) {
    // get the current location of the person
    int row = person->get_location().first;
    int col = person->get_location().second;

    // calculate the new location based on the move
    int new_row = row;
    int new_col = col;
    if (move == 'W') {
        --new_row;
    } else if (move == 'A') {
        --new_col;
    } else if (move == 'S') {
        ++new_row;
    } else if (move == 'D') {
        ++new_col;
    }

    // check if the new location is within the bounds of the maze
    if (new_row < 0 || new_row >= height || new_col < 0 || new_col >= width) {
        return;
    }

    // check if the new location is occupiable
    if (!locations[new_row][new_col]->is_occupiable()) {
        return;
    }

    // update the person's location
    set_location(person, new_row, new_col);
}








/*********************************************************************
** Function: get location and printing
** Description: getting the location and printing the maze
** Parameters:none
** Pre-Conditions:none
** Post-Conditions: printing the maze with the objects
*********************************************************************/



MazeLocation* Maze::get_location(int row, int col) {
    return this->locations[row][col];
}

MazePerson* Maze::get_person(int row, int col) {
    return this->people[row][col];
}


void Maze::print_maze() {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            MazeLocation* loc = this->locations[i][j];
            MazePerson* person = this->people[i][j];
            if (person != NULL) {
                std::cout << person->get_display_character();
            } else {
                std::cout << loc->get_display_character();
            }
        }
        std::cout << std::endl;
    }
}




