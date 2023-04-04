spellbook: spellbookreal.o catalog.o
	g++ -o spellbook spellbookreal.o catalog.o

spellbookreal.o: spellbookreal.cpp
	g++ -c spellbookreal.cpp

catalog.o: catalog.cpp
	g++ -c catalog.cpp

clean:
	rm -f spellbook *.o

