##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC	=	$(SRC_SNAKE)	\
		$(SRC_PACMAN)

OBJ	=	$(OBJ_SNAKE)	\
		$(OBJ_PACMAN)

NAMES	=	$(SNAKE)	\
		$(PACMAN)

SRC_SNAKE=	Snake.cpp

SRC_PACMAN=	Pacman.cpp

OBJ_SNAKE=	$(SRC_SNAKE:.cpp=.o)

OBJ_PACMAN=	$(SRC_PACMAN:.cpp=.o)

INC_DIR	=	../include

CXXFLAGS=	-fPIC -shared -W -Wall -Wextra -I$(INC_DIR)

SNAKE	=	lib_arcade_nibbler.so

PACMAN	=	lib_arcade_pacman.so

all:	snake pacman

snake:	$(OBJ_SNAKE)
	@g++ -o $(SNAKE) $(OBJ_SNAKE) $(CXXFLAGS)

pacman:	$(OBJ_PACMAN)
	@g++ -o $(PACMAN) $(OBJ_PACMAN) $(CXXFLAGS)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAMES)

re:	fclean all

.PHONY: all snake pacman clean fclean re
