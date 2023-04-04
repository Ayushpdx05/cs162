# Variables
CC = g++ -std=c++11 -g
PROG_1 = fractal
PROG_2 = link_list

# target: <list of dependencies>
#    <list of commands>
all: $(PROG_1) $(PROG_2)

$(PROG_1): fractal.cpp
	$(CC) fractal.cpp -o $(PROG_1)

$(PROG_2): linked_list.h node.h test_linked_list.cpp
	$(CC) linked_list.h node.h test_linked_list.cpp -o $(PROG_2)

# Clean target runs below command to remove all listed files
# it also clears any terminal output
clean:
	rm -f *.out *.o $(PROG_1) $(PROG_2)
	clear
