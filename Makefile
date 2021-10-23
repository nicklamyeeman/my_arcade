##
## EPITECH PROJECT, 2019
## OOP_nanotekspice_2018
## File description:
## Makefile
##

SRC_DIR		=	./core/

SRC			=	$(SRC_DIR)Core.cpp		\
				$(SRC_DIR)OpenDir.cpp	\
				$(SRC_DIR)Score.cpp		\
				main.cpp

LIB_DIR		=	lib/

GAME_DIR	=	games/

OBJ			=	$(SRC:.cpp=.o)

INC			=	-I include

CXXFLAGS	+=	$(INC) -W -Wall -Wextra -Werror -std=c++11

NAME		=	arcade

all:	graphicals games core

core:	$(OBJ)
		g++ -o $(NAME) $(OBJ)

games:
		make -sC games/

graphicals:
		make -sC lib/

clean:
		make -sC lib/ clean
		make -sC games/ clean
		rm -f $(OBJ)

fclean:	clean
		make -sC lib/ fclean
		make -sC games/ fclean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all core games graphicals clean fclean re