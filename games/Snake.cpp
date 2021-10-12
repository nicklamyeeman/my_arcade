/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#include "Snake.hpp"

void Snake::newTrigger()
{
    int x = rand() % 15;
    int y = rand() % 10;

    while (_map.at(y)[x] != 'V') {
        x = rand() % 15;
        y = rand() % 10;
    }
    _map.at(y)[x] = 'F';
    _snakeSize += 1;
}

int Snake::gameMechs()
{
    for (int i = 0; i != 200; i++);
    if (_direct == UP)
        return (forwardPressed());
    if (_direct == DOWN)
        return (backwardPressed());
    if (_direct == LEFT)
        return (leftPressed());
    if (_direct == RIGHT)
        return (rightPressed());
    return (1);
}

void Snake::movePlayer()
{
    for (int k = 0; k != (int)_map.size(); k++) {
        int g = 0;
        for (char a : _map.at(k)) {
            if (a == 'P' || a == 'Q')
                _map.at(k)[g] = 'V';
            g++;
        }
    }
    std::vector<int> nPlayer;
    nPlayer.push_back(_newY);
    nPlayer.push_back(_newX);
    for (int i = 0; i != (int)_player.size() - 2; i++)
        nPlayer.push_back(_player.at(i));
    _player = nPlayer;
    for (int i = 0; i != (int)_player.size(); i += 2) {
        if (i == 0)
            _map.at(_player.at(i))[_player.at(i + 1)] = 'P';
        else
            _map.at(_player.at(i + 1))[_player.at(i)] = 'Q';
    }
}

std::vector<std::string> Snake::getMap()
{
    return (_map);
}

int Snake::forwardPressed()
{
    if (_direct != UP) {
        _direct = UP;
        return (1);
    }
    findPlayer();
    _newX = _player.at(0);
    _newY = _player.at(1);
    if (_player.at(1) - 1 >= 0)
        _newY -= 1;
    else
        _newY = _map.size() - 1;
    if (_map.at(_newY)[_player.at(0)] == 'Q' ||
        _map.at(_newY)[_player.at(0)] == 'W')
        return (0);
    if (_map.at(_newY)[_player.at(0)] == 'F') {
        newTrigger();
        _player.push_back(_player.at(_player.size() - 1));
        _player.push_back(_player.at(_player.size() - 2));
    }
    movePlayer();
    return (1);
}

int Snake::backwardPressed()
{
    if (_direct != DOWN) {
        _direct = DOWN;
        return (1);
    }
    findPlayer();
    _newX = _player.at(0); 
    _newY = _player.at(1); 
    if (_player.at(1) + 1 < (int)_map.size())
        _newY += 1;
    else
        _newY = 0;
    if (_map.at(_newY)[_player.at(0)] == 'Q' ||
        _map.at(_newY)[_player.at(0)] == 'W')
        return (0);
    if (_map.at(_newY)[_player.at(0)] == 'F') {
        newTrigger();
        _player.push_back(_player.at(_player.size() - 1));
        _player.push_back(_player.at(_player.size() - 2));
    }
    movePlayer();
    return (1);
}

int Snake::leftPressed()
{
    if (_direct != LEFT) {
        _direct = LEFT;
        return (1);
    }
    findPlayer();
    _newX = _player.at(0); 
    _newY = _player.at(1); 
    if (_player.at(0) - 1 >= 0)
        _newX -= 1;
    else
        _newX = (int)_map.at(0).size() - 1;
    if (_map.at(_player.at(1))[_newX] == 'Q' ||
        _map.at(_player.at(1))[_newX] == 'W')
        return (0);
    if (_map.at(_player.at(1))[_newX] == 'F') {
        newTrigger();
        _player.push_back(_player.at(_player.size() - 1));
        _player.push_back(_player.at(_player.size() - 2));
    }
    movePlayer();
    return (1);
}

int Snake::rightPressed()
{
    if (_direct != RIGHT) {
        _direct = RIGHT;
        return (1);
    }
    findPlayer();
    _newX = _player.at(0); 
    _newY = _player.at(1); 
    if (_player.at(0) + 1 < (int)_map.at(0).size())
        _newX += 1;
    else
        _newX = 0;
    if (_map.at(_player.at(1))[_newX] == 'Q' ||
        _map.at(_player.at(1))[_newX] == 'W')
        return (0);
    if (_map.at(_player.at(1))[_newX] == 'F') {
        newTrigger();
        _player.push_back(_player.at(_player.size() - 1));
        _player.push_back(_player.at(_player.size() - 2));
    }
    movePlayer();
    return (1);
}

void Snake::findPlayer()
{
    std::string tmp;

    for (int i = 0; i != (int)_map.size(); i++) {
        tmp = _map.at(i);
        if (tmp.find("P") != tmp.npos) {
            _player.at(0) = tmp.find("P");
            _player.at(1) = i;
        }
    }
}

void Snake::setMap()
{
    std::ifstream file("./assets/maps/snake.txt");
    std::string tmp;

 	if (!file.is_open())
        return;
    while (std::getline(file, tmp)) {
        if (tmp.empty())
            continue;
        _map.push_back(tmp);
    }
    file.close();
}

Snake::Snake()
{
    srand(time(0));
    setMap();
    _direct = NONE;
    _player.push_back(0);
    _player.push_back(0);
    _snakeSize = 0;
}

Snake::~Snake()
{
}

extern "C" {
    IGame *startingBlock() {
        return (new Snake());
    }
}
