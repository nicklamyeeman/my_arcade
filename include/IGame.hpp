/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <iostream>
#include <vector>
#include <fstream>

class IGame {
	public:
        typedef enum {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            NONE
        } e_direct;
        virtual ~IGame() = default;

        /* Getter */
        virtual std::vector<std::string> getMap() = 0;

        /* Setter */
        virtual void setMap() = 0;

        virtual int inPressed() = 0;
        virtual int outPressed() = 0;
        virtual int forwardPressed() = 0;
        virtual int backwardPressed() = 0;
        virtual int leftPressed() = 0;
        virtual int rightPressed() = 0;

        virtual void findPlayer() = 0;
        virtual void movePlayer() = 0;

        virtual int gameMechs() = 0;
        virtual void newTrigger() = 0;

	protected:
        e_direct _direct;
	private:
};

#endif /* !IGAME_HPP_ */
