OBJS	= driver.o game.o Instructor.o IntrepeidStudent.o Maze.o MazeLocation.o MazePerson.o OpenSpace.o TA.o Wall.o
SOURCE	= driver.cpp game.cpp Instructor.cpp IntrepeidStudent.cpp Maze.cpp MazeLocation.cpp MazePerson.cpp OpenSpace.cpp TA.cpp Wall.cpp
HEADER	= game.h Instructor.h IntrepeidStudent.h Maze.h MazeLocation.h MazePerson.h OpenSpace.h TA.h Wall.h
OUT	= game
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 

game.o: game.cpp
	$(CC) $(FLAGS) game.cpp 

Instructor.o: Instructor.cpp
	$(CC) $(FLAGS) Instructor.cpp 

IntrepeidStudent.o: IntrepeidStudent.cpp
	$(CC) $(FLAGS) IntrepeidStudent.cpp 

Maze.o: Maze.cpp
	$(CC) $(FLAGS) Maze.cpp 

MazeLocation.o: MazeLocation.cpp
	$(CC) $(FLAGS) MazeLocation.cpp 

MazePerson.o: MazePerson.cpp
	$(CC) $(FLAGS) MazePerson.cpp 

OpenSpace.o: OpenSpace.cpp
	$(CC) $(FLAGS) OpenSpace.cpp 

TA.o: TA.cpp
	$(CC) $(FLAGS) TA.cpp 

Wall.o: Wall.cpp
	$(CC) $(FLAGS) Wall.cpp 


clean:
	rm -f $(OBJS) $(OUT)