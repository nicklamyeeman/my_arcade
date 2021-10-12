/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** DisplayNcurses
*/

#ifndef DISPLAYNCURSES_HPP_
    #define DISPLAYNCURSES_HPP_

#include <curses.h>
#include <vector>
#include <fstream>
#include "IDisplay.hpp"

class DisplayNcurses : public IDisplay {
public:
    DisplayNcurses();
    ~DisplayNcurses();

    bool winOpen();
    void winClear();
    void winClose();
    void winInit();

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

    void displayUsername(std::string &username);
    std::string usernameEntry(std::string &username);
    void displayMenu(std::string &game, std::vector<std::string> &userInfo);
    void displayScoreMenu(std::vector<std::string> &userInfo) { (void)userInfo; };
    void displayGame(std::vector<std::string> &map);

protected:
private:
    WINDOW *_window;
    int _k;

    std::vector<std::string> _username;
    std::vector<std::string> _menu;
    std::vector<std::string> _game;
};

#endif /* !DISPLAYNCURSES_HPP_ */
