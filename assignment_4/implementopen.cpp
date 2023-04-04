#ifndef CONCRETE_MAZE_LOCATION_H
#define CONCRETE_MAZE_LOCATION_H

#include "MazeLocation.h"

class ConcreteMazeLocation : public MazeLocation {
public:
    ConcreteMazeLocation(char display_char);
    virtual ~ConcreteMazeLocation();

    virtual char get_display_character() const;

private:
    char display_character_;
};

#endif // CONCRETE_MAZE_LOCATION_H
