/*
** EPITECH PROJECT, 2019
** graphic
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <iostream>
#include <vector>

class IDisplay {
	public:
		virtual ~IDisplay() = default;

        virtual bool winOpen() = 0;
        virtual void winClear() = 0;
        virtual void winClose() = 0;
        virtual void winInit() = 0;

        virtual bool pressEnter() = 0;
        virtual bool pressPrevLib() = 0;
        virtual bool pressNextLib() = 0;
        virtual bool pressPrevGame() = 0;
        virtual bool pressNextGame() = 0;
        virtual bool pressRestartGame() = 0;
        virtual bool pressBackMenu() = 0;
        virtual bool pressQuit() = 0;
        virtual bool pressForward() = 0;
        virtual bool pressLeft() = 0;
        virtual bool pressBackward() = 0;
        virtual bool pressRight() = 0;
        virtual bool pressIn() = 0;
        virtual bool pressOut() = 0;

        virtual void displayUsername(std::string &username) = 0;
        virtual std::string usernameEntry(std::string &username) = 0;
        virtual void displayMenu(std::string &game, std::vector<std::string> &userInfo) = 0;
        virtual void displayScoreMenu(std::vector<std::string> &userInfo) = 0;
        virtual void displayGame(std::vector<std::string> &map) = 0;

	protected:
	private:
};

#endif /* !IDISPLAY_HPP_ */
