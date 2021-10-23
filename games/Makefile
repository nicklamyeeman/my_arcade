##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC			=	$(SRC_SNAKE)	\
				$(SRC_PACMAN)

OBJ			=	$(OBJ_SNAKE)	\
				$(OBJ_PACMAN)

NAMES		=	$(SNAKE)		\
				$(PACMAN)

SRC_SNAKE	=	Snake.cpp

SRC_PACMAN	=	Pacman.cpp

OBJ_SNAKE	=	$(SRC_SNAKE:.cpp=.o)

OBJ_PACMAN	=	$(SRC_PACMAN:.cpp=.o)

INC			=	-I ../include

CXXFLAGS 	=	-W -Wall -Wextra -Werror -std=c++11

SNAKE		=	lib_arcade_nibbler.so

PACMAN		=	lib_arcade_pacman.so

all:	snake pacman

snake:
		g++ -c -o $(OBJ_SNAKE) $(INC) $(CXXFLAGS) $(SRC_SNAKE)
		g++ -fPIC -shared -o $(SNAKE) $(INC) $(CXXFLAGS) $(OBJ_SNAKE)

pacman:
		g++ -c -o $(OBJ_PACMAN) $(INC) $(CXXFLAGS) $(SRC_PACMAN)
		g++ -fPIC -shared -o $(PACMAN) $(INC) $(CXXFLAGS) $(OBJ_PACMAN)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAMES)

re:		fclean all

.PHONY: all snake pacman clean fclean re
