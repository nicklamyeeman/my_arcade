/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** DisplaySDL
*/

#include "DisplaySDL.hpp"

bool DisplaySDL::pressForward()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_z);
}

bool DisplaySDL::pressLeft()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_q);
}

bool DisplaySDL::pressBackward()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_s);
}

bool DisplaySDL::pressRight()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_d);
}

bool DisplaySDL::pressIn()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_k);
}

bool DisplaySDL::pressOut()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_p);
}

bool DisplaySDL::pressEnter()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_RETURN);
}

bool DisplaySDL::pressNextLib()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_F3);
}

bool DisplaySDL::pressPrevLib()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_F2);
}

bool DisplaySDL::pressNextGame()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_F5);
}

bool DisplaySDL::pressPrevGame()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_F4);
}

bool DisplaySDL::pressRestartGame()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_DELETE);
}

bool DisplaySDL::pressBackMenu()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_b);
}

bool DisplaySDL::pressQuit()
{
    return (_event.type == SDL_KEYDOWN &&
            _event.key.keysym.sym == SDLK_ESCAPE);
}

void DisplaySDL::displayGame(std::vector<std::string> &map)
{
    int texW = 0;
    int texH = 0;
    int x = _x;
    int y = _y;

    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT)
            _running = false;
    }
    _background = SDL_CreateTextureFromSurface(_renderer, _game);
    SDL_RenderCopy(_renderer, _background, NULL, NULL);
    for (int i = 0; (int)map.size() != i; i++) {
        for (char a : map.at(i)) {
            if (a == 'W')
                _map = SDL_CreateTextureFromSurface(_renderer, _W);
            if (a == 'V')
                _map = SDL_CreateTextureFromSurface(_renderer, _V);
            if (a == 'P')
                _map = SDL_CreateTextureFromSurface(_renderer, _P);
            if (a == 'Q')
                _map = SDL_CreateTextureFromSurface(_renderer, _Q);
            if (a == 'F')
                _map = SDL_CreateTextureFromSurface(_renderer, _F);
            SDL_QueryTexture(_map, NULL, NULL, &texW, &texH);
            SDL_Rect dstrect = { x, y, texW, texH };
            SDL_RenderCopy(_renderer, _map, NULL, &dstrect);
            SDL_DestroyTexture(_map);
            x += 53;
        }
        x = _x;
        y += 53;
    }
    SDL_DestroyTexture(_background);
    SDL_RenderPresent(_renderer);
}

void DisplaySDL::displayScoreMenu(std::vector<std::string> &userInfo)
{
    (void)userInfo;
}

void DisplaySDL::displayMenu(std::string &game, std::vector<std::string> &userInfo)
{
    int texW = 0;
    int texH = 0;
    
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT)
            _running = false;
    }
   _text = TTF_RenderText_Solid(_font, game.c_str() + 11, _white);
    _textT = SDL_CreateTextureFromSurface(_renderer, _text);
    _background = SDL_CreateTextureFromSurface(_renderer, _menu);
    SDL_RenderCopy(_renderer, _background, NULL, NULL);
    SDL_QueryTexture(_textT, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 400, 330, texW, texH };
    SDL_RenderCopy(_renderer, _textT, NULL, &dstrect);
    SDL_RenderPresent(_renderer);
    SDL_DestroyTexture(_background);
    SDL_DestroyTexture(_textT);
    displayScoreMenu(userInfo);
}

void DisplaySDL::displayUsername(std::string &username)
{
    int texW = 0;
    int texH = 0;
    
    SDL_RenderCopy(_renderer, _background, NULL, NULL);
    SDL_QueryTexture(_textT, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 400, 330, texW, texH };
    SDL_RenderCopy(_renderer, _textT, NULL, &dstrect);
    SDL_RenderPresent(_renderer);
    SDL_DestroyTexture(_background);
    SDL_DestroyTexture(_textT);
}

std::string DisplaySDL::usernameEntry(std::string &username)
{
    SDL_Event evt;

    while (SDL_PollEvent(&evt)) {
        if (evt.type == SDL_QUIT)
            _running = false;
        if (evt.type == SDL_TEXTINPUT)
            username += evt.text.text;
    }
    if (_event.type == SDL_KEYDOWN &&
        _event.key.keysym.sym == SDLK_BACKSPACE && username.size() > 0)
        username.pop_back();
    _text = TTF_RenderText_Solid(_font, username.c_str(), _white);
    _textT = SDL_CreateTextureFromSurface(_renderer, _text);
    _background = SDL_CreateTextureFromSurface(_renderer, _username);
    displayUsername(username);
    return (username);
}

bool DisplaySDL::winOpen()
{
    return (_running);
}

void DisplaySDL::winClose()
{
    _running = false;
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
    TTF_Quit();
}

void DisplaySDL::winInit()
{
    SDL_PollEvent(&_event);
    _running = true;
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    _font = TTF_OpenFont("./assets/fonts/font.ttf", 80);

    _username = IMG_Load("./assets/backgrounds/username_bg.png");
    _menu = IMG_Load("./assets/backgrounds/menu_bg.png");
    _game = IMG_Load("./assets/backgrounds/game_bg.png");

    _W = IMG_Load("./assets/textures/W.png");
    _V = IMG_Load("./assets/textures/V.png");
    _P = IMG_Load("./assets/textures/P.png");
    _Q = IMG_Load("./assets/textures/Q.png");
    _F = IMG_Load("./assets/textures/F.png");
    _x = 145;
    _y = 111;
}

void DisplaySDL::winClear()
{
    for (int i = 0; i != 45000000; i++);
    SDL_PollEvent(&_event);
    SDL_RenderClear(_renderer);
}

DisplaySDL::DisplaySDL()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _window = SDL_CreateWindow("SDL", 0, 0, 1080, 720, SDL_WINDOW_SHOWN);
}

DisplaySDL::~DisplaySDL()
{
}

extern "C" {
    IDisplay *startingBlock() {
        return (new DisplaySDL());
    }
}
