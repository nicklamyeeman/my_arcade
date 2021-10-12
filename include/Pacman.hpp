/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "IGame.hpp"

class Pacman :public IGame {
	public:
		Pacman();
		~Pacman();

        /* Getter */
        std::vector<std::string> getMap() { return (_map); };

        /* Setter */
        void setMap();

        int inPressed() { return (1); };
        int outPressed() { return (1); };
        int forwardPressed();
        int backwardPressed();
        int leftPressed();
        int rightPressed();

        void findPlayer();
        void movePlayer();

        int gameMechs() { return (1); };
        void newTrigger() {};
	protected:
	private:
        std::vector<std::string> _map;
        std::vector<int> _player;
};

#endif /* !PACMAN_HPP_ */
