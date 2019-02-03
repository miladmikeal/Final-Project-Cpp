OBJS	= main.o Board.o Space.o Soldier.o Comrade.o Mine.o Menu.o utilityFunctions.o
SOURCE	= main.cpp Board.cpp Space.cpp Soldier.cpp Comrade.cpp Mine.cpp Menu.cpp utilityFunctions.cpp
HEADER	= Board.hpp Space.hpp Soldier.hpp Comrade.hpp Mine.hpp Menu.hpp utilityFunctions.hpp
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall -std=c++11
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

Board.o: Board.cpp
	$(CC) $(FLAGS) Board.cpp

Space.o: Space.cpp
	$(CC) $(FLAGS) Space.cpp

Soldier.o: Soldier.cpp
	$(CC) $(FLAGS) Soldier.cpp

Comrade.o: Comrade.cpp
	$(CC) $(FLAGS) Comrade.cpp

Mine.o: Mine.cpp
	$(CC) $(FLAGS) Mine.cpp

Menu.o: Menu.cpp
	$(CC) $(FLAGS) Menu.cpp

utilityFunctions.o: utilityFunctions.cpp
	$(CC) $(FLAGS) utilityFunctions.cpp


clean:
	rm -f $(OBJS) $(OUT)