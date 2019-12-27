# To link <make>
# To clear <make clear>

OBJ = main.o Warrior.o Weapon.o rndWpn.o input.o
SRC = main.cpp Warrior.cpp Weapon.cpp rndWpn.cpp input.cpp
CC = g++
FLAGS = -std=c++17

all: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o game
	
main.o: Warrior.h Weapon.h functions.h
	$(CC) $(FLAGS) -c main.cpp
Warrior.o: Warrior.h
	$(CC) $(FLAGS) -c Warrior.cpp
Weapon.o: Weapon.h
	$(CC) $(FLAGS) -c Weapon.cpp
rndWpn.o:
	$(CC) $(FLAGS) -c rndWpn.cpp
input.o:
	$(CC) $(FLAGS) -c input.cpp

clear: 
	rm $(OBJ)