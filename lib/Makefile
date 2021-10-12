##
## EPITECH PROJECT, 2019
## graphic
## File description:
## Makefile
##

SRC	=	$(SRC_SFML)	\
		$(SRC_CURSES)	\
		$(SRC_SDL)

OBJ	=	$(OBJ_CURSES)	\
		$(OBJ_SFML)	\
		$(OBJ_SDL)

NAMES	=	$(SFML)		\
		$(CURSES)	\
		$(SDL)

SRC_SFML=	DisplaySFML.cpp

OBJ_SFML=	$(SRC_SFML:.cpp=.o)

SRC_CURSES=	DisplayNcurses.cpp

OBJ_CURSES=	$(SRC_CURSES:.cpp=.o)

SRC_SDL	=	DisplaySDL.cpp

OBJ_SDL	=	$(SRC_SDL:.cpp=.o)

INC_DIR	=	../include

CXXFLAGS=	-fPIC -shared -W -Wall -Wextra -I$(INC_DIR)

SFML	=	lib_arcade_sfml.so

CURSES	=	lib_arcade_ncurses.so

SDL	=	lib_arcade_sdl.so

all:	sfml curses sdl

sfml:	$(OBJ_SFML)
	@g++ -o $(SFML) $(OBJ_SFML) $(CXXFLAGS) -lsfml-graphics -lsfml-window

curses: $(OBJ_CURSES)
	@g++ -o $(CURSES) $(OBJ_CURSES) $(CXXFLAGS) -lncurses

sdl:	$(OBJ_SDL)
	@g++ -o $(SDL) $(OBJ_SDL) $(CXXFLAGS) -lSDL2 -lSDL2_image -lSDL2_ttf

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAMES)

re:	fclean all

.PHONY: all sfml sdl curses clean fclean re