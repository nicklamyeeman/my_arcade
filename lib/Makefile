##
## EPITECH PROJECT, 2019
## graphic
## File description:
## Makefile
##

SRC			=	$(SRC_SFML)		\
				$(SRC_CURSES)	\
				$(SRC_SDL)

OBJ			=	$(OBJ_SFML)		\
				$(OBJ_CRUSES)	\
				$(OBJ_SDL)

NAMES		=	$(SFML)			\
				$(CURSES)		\
				$(SDL)

SRC_SFML	=	DisplaySFML.cpp

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

SRC_CURSES	=	DisplayNcurses.cpp

OBJ_CURSES	=	$(SRC_CURSES:.cpp=.o)

SRC_SDL		=	DisplaySDL.cpp

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)

INC			=	-I ../include

CXXFLAGS	=	-W -Wall -Wextra -Werror -std=c++11

SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

CURSESFLAGS	=	-lncurses

SDLFLAGS	=	-lSDL2 -lSDL2_image -lSDL2_ttf

SFML		=	lib_arcade_sfml.so

CURSES		=	lib_arcade_ncurses.so

SDL			=	lib_arcade_sdl.so

all:	sfml curses sdl

sfml:
		g++ -c -o $(OBJ_SFML) $(INC) $(CXXFLAGS) $(SRC_SFML)
		g++ -fPIC -shared -o $(SFML) $(INC) $(CXXFLAGS) $(SFMLFLAGS) $(OBJ_SFML)

curses:
		g++ -c -o $(OBJ_CURSES) $(INC) $(CXXFLAGS) $(SRC_CURSES)
		g++ -fPIC -shared -o $(CURSES) $(INC) $(CXXFLAGS) $(CURSESFLAGS) $(OBJ_CURSES)

sdl:
		g++ -c -o $(OBJ_SDL) $(INC) $(CXXFLAGS) $(SRC_SDL)
		g++ -fPIC -shared -o $(SDL) $(INC) $(CXXFLAGS) $(SDLFLAGS) $(OBJ_SDL)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAMES)

re:		fclean all

.PHONY: all sfml sdl curses clean fclean re