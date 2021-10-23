/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** DisplaySDL
*/

#ifndef DISPLAYSDL_HPP_
#define DISPLAYSDL_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include "IDisplay.hpp"

class DisplaySDL : public IDisplay {
	public:
		DisplaySDL();
		~DisplaySDL();

        /* window global*/
        bool winOpen();
        void winClear();
        void winClose();
        void winInit();

        /* inputs */
        bool pressEnter();
        bool pressPrevLib();
        bool pressNextLib();
        bool pressPrevGame();
        bool pressNextGame();
        bool pressRestartGame();
        bool pressBackMenu();
        bool pressQuit();
        bool pressForward();
        bool pressLeft();
        bool pressBackward();
        bool pressRight();
        bool pressIn();
        bool pressOut();


        /* displays */
        void displayUsername(std::string &username);
        std::string usernameEntry(std::string &username);
        void displayMenu(std::string &game, std::vector<std::string> &userInfo);
        void displayScoreMenu(std::vector<std::string> &userInfo);
        void displayGame(std::vector<std::string> &map);

	protected:
	private:
        SDL_Window *_window;
        SDL_Event _event;
        SDL_Renderer *_renderer;
        SDL_Texture *_background;
        SDL_Texture *_map;
        SDL_Color _white = { 255, 255, 255, 255 };
        TTF_Font *_font;
        bool _running = true;

        SDL_Surface *_text;
        SDL_Texture *_textT;
        SDL_Surface *_username;
        SDL_Surface *_menu;
        SDL_Surface *_game;

        SDL_Surface *_W;
        SDL_Surface *_V;
        SDL_Surface *_Q;
        SDL_Surface *_P;
        SDL_Surface *_F;

        int _x;
        int _y;
};

#endif /* !DISPLAYSDL_HPP_ */
