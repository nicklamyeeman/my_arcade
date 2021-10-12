/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "IGame.hpp"

class Snake : public IGame {
	public:
		Snake();
		~Snake();

        /* Getter */
        std::vector<std::string> getMap();

        /* Setter */
        void setMap();

        int inPressed() { return (1); };
        int outPressed() { return (1); };
        int forwardPressed();
        int backwardPressed();
        int leftPressed();
        int rightPressed();

        void findPlayer();

        int gameMechs();
        void newTrigger();
        void movePlayer();
	protected:
	private:
        int _snakeSize;
        std::vector<std::string> _map;
        std::vector<int> _player;
        int _newX;
        int _newY;
};

#endif /* !SNAKE_HPP_ */
