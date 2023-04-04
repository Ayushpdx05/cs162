CC = g++ -g -std=c++11
EXE_FILE = coffee

all: $(EXE_FILE)

$(EXE_FILE): prog.cpp shop.o menu.o coffee.o order.o
	$(CC) -o $(EXE_FILE) prog.cpp shop.o menu.o coffee.o order.o 

shop.o: shop.cpp shop.h
	$(CC) -c shop.cpp

menu.o: menu.cpp menu.h
	$(CC) -c menu.cpp

coffee.o: coffee.cpp coffee.h
	$(CC) -c coffee.cpp

order.o: order.cpp order.h
	$(CC) -c order.cpp

clean:
	rm -f $(EXE_FILE) *.o