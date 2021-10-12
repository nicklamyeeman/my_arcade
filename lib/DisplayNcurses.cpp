/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** DisplayNcurses
*/

#include "DisplayNcurses.hpp"

bool DisplayNcurses::pressEnter()
{
    return (_k == 10);
}

bool DisplayNcurses::pressPrevLib()
{
    return (_k == KEY_F(2));
}

bool DisplayNcurses::pressNextLib()
{
    return (_k == KEY_F(3));
}

bool DisplayNcurses::pressPrevGame()
{
    return (_k == KEY_F(4));
}

bool DisplayNcurses::pressNextGame()
{
    return (_k == KEY_F(5));
}

bool DisplayNcurses::pressRestartGame()
{
    return (_k == 330);
}

bool DisplayNcurses::pressBackMenu()
{
    return (_k == 98);
}

bool DisplayNcurses::pressQuit()
{
    return (_k == 27);
}

bool DisplayNcurses::pressForward()
{
    return (_k == 'z');
}

bool DisplayNcurses::pressLeft()
{
    return (_k == 'q');
}

bool DisplayNcurses::pressBackward()
{
    return (_k == 's');
}

bool DisplayNcurses::pressRight()
{
    return (_k == 'd');
}

bool DisplayNcurses::pressIn()
{
    return (_k == 'k');
}

bool DisplayNcurses::pressOut()
{
    return (_k == 'p');
}

void DisplayNcurses::displayGame(std::vector<std::string> &map)
{
    int x = 29;
    int y = 8;
    std::string tmp;

    for (int i = 0; i != (int)_game.size(); i++)
        mvprintw(i + 1, 1, _game.at(i).c_str());
    for (int k = 0; k != (int)map.size(); k++) {
        tmp = map.at(k);
        for (char a : tmp) {
            if (a == 'W')
                mvprintw(y, x, "%c", '*');
            if (a == 'V')
                mvprintw(y, x, "%c", ' ');
            if (a == 'P')
                mvprintw(y, x, "%c", 'P');
            if (a == 'Q')
                mvprintw(y, x, "%c", 'o');
            if (a == 'F')
                mvprintw(y, x, "%c", '@');
            x += 1;
        }
        x = 29;
        y += 1;
    }
    _k = getch();
}

void DisplayNcurses::displayMenu(std::string &game, std::vector<std::string> &userInfo)
{
    (void)userInfo;
    curs_set(0);
    for (int i = 0; i != (int)_menu.size(); i++)
        mvprintw(i + 1, 1, _menu.at(i).c_str());
    mvprintw(13, 32, game.c_str() + 11);
    _k = getch();
}

void DisplayNcurses::displayUsername(std::string &username)
{
    for (int i = 0; i != (int)_username.size(); i++)
        mvprintw(i + 1, 1, _username.at(i).c_str());
    mvprintw(13, 30, username.c_str());
}

std::string DisplayNcurses::usernameEntry(std::string &username)
{
    displayUsername(username);
    _k = getch();
    if (_k > 0) {
        if (_k == KEY_BACKSPACE && username.size() > 0)
            username.pop_back();
        else
            username += _k;
    }
    return (username);
}

void DisplayNcurses::winInit()
{
    _k = 0;
    keypad(_window, true);
    noecho();
    halfdelay(3);
}

void DisplayNcurses::winClose()
{
    _k = -2;
    endwin();
}

bool DisplayNcurses::winOpen()
{
    return (_k != -2);
}

void DisplayNcurses::winClear()
{
    wclear(_window);
    wrefresh(_window);
}

DisplayNcurses::DisplayNcurses()
{
    _window = initscr();
    std::ifstream user("./assets/backgrounds/username_bg.txt");
    std::ifstream menu("./assets/backgrounds/menu_bg.txt");
    std::ifstream game("./assets/backgrounds/game_bg.txt");
    std::string tmp;

 	if (!user.is_open() || !menu.is_open() || !game.is_open())
        exit(EXIT_FAILURE);
    while (std::getline(user, tmp))
        _username.push_back(tmp);
    user.close();
    while (std::getline(menu, tmp))
        _menu.push_back(tmp);
    menu.close();
    while (std::getline(game, tmp))
        _game.push_back(tmp);
    game.close();
}

DisplayNcurses::~DisplayNcurses()
{
    _k = -2;
    endwin();
}

extern "C" {
    IDisplay *startingBlock() {
        return (new DisplayNcurses());
    }
}