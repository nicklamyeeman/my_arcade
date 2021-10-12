/*
** EPITECH PROJECT, 2019
** graphic
** File description:
** Core
*/

#include "Core.hpp"
#include <dlfcn.h>
#include <sys/types.h>
#include <dirent.h>

void Core::prevLib()
{
    _lib->winClose();
    delete(_lib);
    _dlib.closeLib();

    _libpath.assign("./lib/");
    if (_actualLib - 1 >= 0)
        _actualLib = _actualLib - 1;
    else
        _actualLib = (int)_libList.size() - 1;
    _libpath.append(_libList.at(_actualLib));

    _lib = _dlib.openLib(_libpath);
    _lib->winInit();
    _input = PREV_LIB;
}

void Core::nextLib()
{
    _lib->winClose();
    delete(_lib);
    _dlib.closeLib();

    _libpath.assign("./lib/");
    if (_actualLib + 1 > (int)_libList.size() - 1)
        _actualLib = 0;
    else
        _actualLib += 1;
    _libpath.append(_libList.at(_actualLib));

    _lib = _dlib.openLib(_libpath);
    _lib->winInit();
    _input = NEXT_LIB;
}

void Core::prevGame()
{
    if (_actualGame + 1 > (int)_gameList.size() - 1)
        _actualGame = 0;
    else
        _actualGame += 1;
    delete (_game);
    _dgame.closeLib();
    _gamepath.assign("./games/");
    _gamepath.append(_gameList.at(_actualGame));
    _game = _dgame.openLib(_gamepath);
    _input = PREV_GAME;
}

void Core::nextGame()
{
    if (_actualGame - 1 < 0)
        _actualGame = _gameList.size() - 1;
    else
        _actualGame -= 1;
    delete (_game);
    _dgame.closeLib();
    _gamepath.assign("./games/");
    _gamepath.append(_gameList.at(_actualGame));
    _game = _dgame.openLib(_gamepath);
    _input = NEXT_GAME;
}

void Core::checkGlobalInputs()
{
    if (_lib->pressQuit())
        _lib->winClose();
    if (_lib->pressPrevLib() && _input == NONE)
        prevLib();
    if (_lib->pressNextLib() && _input == NONE)
        nextLib();
    if (_lib->pressBackMenu() && _state == GAME) {
        delete (_game);
        _dgame.closeLib();
        _state = MENU;
    }
    if (_lib->pressRestartGame() && _state == GAME && _input == NONE) {
        delete (_game);
        _dgame.closeLib();
        _gamepath.assign("./games/");
        _gamepath.append(_gameList.at(_actualGame));
        _game = _dgame.openLib(_gamepath);
        _input = RESTART;
    }
    if (_lib->pressPrevGame() && _state == GAME && _input == NONE)
        prevGame();
    if (_lib->pressNextGame() && _state == GAME && _input == NONE)
        nextGame();
}

void Core::checkMenuInputs()
{
    if (_lib->pressIn()) {
        _state = GAME;
        _gamepath.assign("./games/");
        _gamepath.append(_gameList.at(_actualGame));
        _game = _dgame.openLib(_gamepath);
    }
    if (_lib->pressOut())
        _state = USERNAME;
    if (_lib->pressLeft()) {
        if (_actualGame + 1 > (int)_gameList.size() - 1)
            _actualGame = 0;
        else
            _actualGame += 1;
    }
    if (_lib->pressRight()) {
        if (_actualGame - 1 < 0)
            _actualGame = _gameList.size() - 1;
        else
            _actualGame -= 1;
    }
}

int Core::checkGameInputs()
{
    if (_lib->pressForward())
        if (_game->forwardPressed() == 0)
            return (0);
    if (_lib->pressBackward())
        if (_game->backwardPressed() == 0)
            return (0);
    if (_lib->pressLeft())
        if (_game->leftPressed() == 0)
            return (0);
    if (_lib->pressRight())
        if (_game->rightPressed() == 0)
            return (0);
    return (1);
}

void Core::checkState()
{
    if (_state == USERNAME) {
        _username = _lib->usernameEntry(_username);
        if (_lib->pressEnter()) {
            _userInfo = _score.findUser(_username);
            _state = MENU;
            _enter = 1;
        }
    }
    if (_state == MENU && _enter == 0) {
        checkMenuInputs();
        _lib->displayMenu(_gameList.at(_actualGame), _userInfo);
    }
    if (_state == GAME && _enter == 0) {
        if (checkGameInputs() == 0) {
            delete (_game);
            _dgame.closeLib();
            _state = MENU;
        } else if (_game->gameMechs() == 0) {
            delete (_game);
            _dgame.closeLib();
            _state = MENU;
        } else {
            _map = _game->getMap();
            _lib->displayGame(_map);
        }
    }
}

void Core::arcadeLoop()
{
    int sleep = 0;

    _lib->winInit();
    while (_lib->winOpen()) {
        checkGlobalInputs();
        if (sleep > 1000) {
            sleep = 0;
            _input = NONE;
            _enter = 0;
            checkState();
            _lib->winClear();
        }
        sleep += 1;
    }
    _lib->winClose();
}

Core::Core(char *libpath)
{
    /* Paths */
    _libpath.assign(libpath);
    OpenDir libdir("./lib/", "lib_");
    _libList = libdir.getDirContent();
    _actualLib = libdir.findFile(_libpath);

    OpenDir gamedir("./games/", "lib_arcade_");
    _gameList = gamedir.getDirContent();
    _actualGame = 0;

    /* DLLoaders */
    _lib = _dlib.openLib(_libpath);

    /* Enums */
    _state = USERNAME;
    _input = NONE;
    _enter = 0;

    /* Inputs */
}

Core::~Core()
{
    delete(_lib);
    if (_state == GAME) {
        delete(_game);
        _dgame.closeLib();
    }
    _dlib.closeLib();
}
