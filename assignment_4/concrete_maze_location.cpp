#include "concrete_maze_location.h"

ConcreteMazeLocation::ConcreteMazeLocation(char display_char) : display_character_(display_char) {}

ConcreteMazeLocation::~ConcreteMazeLocation() {}

char ConcreteMazeLocation::get_display_character() const {
    return display_character_;
}
