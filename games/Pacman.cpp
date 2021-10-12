/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#include "Pacman.hpp"

void Pacman::movePlayer()
{
}

int Pacman::forwardPressed()
{
    findPlayer();
    if (_player.at(1) - 1 >= 0)
        _player.at(1) -= 1;
    _map.at(_player.at(1) + 1).replace(_player.at(0), 1, "V");
    if (_map.at(_player.at(1))[_player.at(0)] == 'Q' ||
        _map.at(_player.at(1))[_player.at(0)] == 'W')
        return (0);
    _map.at(_player.at(1)).replace(_player.at(0), 1, "P");
    return (1);
}

int Pacman::backwardPressed()
{
    findPlayer();
    if (_player.at(1) + 1 < (int)_map.size())
        _player.at(1) += 1;
    _map.at(_player.at(1) - 1).replace(_player.at(0), 1, "V");
    if (_map.at(_player.at(1))[_player.at(0)] == 'Q' ||
        _map.at(_player.at(1))[_player.at(0)] == 'W')
        return (0);
    _map.at(_player.at(1)).replace(_player.at(0), 1, "P");
    return (1);
}

int Pacman::leftPressed()
{
    findPlayer();
    if (_player.at(0) - 1 >= 0)
        _player.at(0) -= 1;
    _map.at(_player.at(1)).replace(_player.at(0) + 1, 1, "V");
    if (_map.at(_player.at(1))[_player.at(0)] == 'Q' ||
        _map.at(_player.at(1))[_player.at(0)] == 'W')
        return (0);
    _map.at(_player.at(1)).replace(_player.at(0), 1, "P");
    return (1);
}

int Pacman::rightPressed()
{
    findPlayer();
    if (_player.at(0) + 1 < (int)_map.at(0).size())
        _player.at(0) += 1;
    _map.at(_player.at(1)).replace(_player.at(0) - 1, 1, "V");
    if (_map.at(_player.at(1))[_player.at(0)] == 'Q' ||
        _map.at(_player.at(1))[_player.at(0)] == 'W')
        return (0);
    _map.at(_player.at(1)).replace(_player.at(0), 1, "P");
    return (1);
}

void Pacman::findPlayer()
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

void Pacman::setMap()
{
    std::ifstream file("./assets/maps/pacman.txt");
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

Pacman::Pacman()
{
    setMap();
    _player.push_back(0);
    _player.push_back(0);
}

Pacman::~Pacman()
{
}

extern "C" {
    IGame *startingBlock() {
        return (new Pacman());
    }
}
