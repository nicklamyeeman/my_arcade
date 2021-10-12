/*
** EPITECH PROJECT, 2019
** graphic
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <vector>
#include <iostream>
#include "IDisplay.hpp"
#include "DLLoader.hpp"
#include "OpenDir.hpp"
#include "IGame.hpp"
#include "Score.hpp"

class Core {
    typedef enum {
        USERNAME,
        MENU,
        GAME
    } e_state;
    typedef enum {
        NONE,
        RESTART,
        PREV_LIB,
        NEXT_LIB,
        PREV_GAME,
        NEXT_GAME,
        QUIT
    } e_inputs;
public:
    Core(char *libpath);
    ~Core();

    int findLibPos();
    void arcadeLoop();
    void checkState();
    void checkMenuInputs();
    int checkGameInputs();

    void checkGlobalInputs();
    void prevLib();
    void nextLib();
    void prevGame();
    void nextGame();
    void restartGame();
    void backMenu();

protected:
private:
    /* Paths */
    std::string _libpath;
    std::string _gamepath;
    std::vector<std::string> _libList;
    int _actualLib;
    std::vector<std::string> _gameList;
    int _actualGame;

    /* DLLoaders */
    DLLoader<IDisplay *> _dlib;
    DLLoader<IGame *> _dgame;
    IDisplay *_lib;
    IGame *_game;

    /* Enums */
    e_state _state;
    e_inputs _input;
    bool _enter;

    /* Username */
    std::string _username;

    /* Game */
    std::vector<std::string> _map;

    /* Score */
    Score _score;
    std::vector<std::string> _userInfo;
};

#endif /* !CORE_HPP_ */
