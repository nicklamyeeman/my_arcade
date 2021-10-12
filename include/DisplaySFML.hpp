/*
** EPITECH PROJECT, 2019
** graphic
** File description:
** DisplaySFML
*/

#ifndef DISPLAYSFML_HPP_
#define DISPLAYSFML_HPP_

#include <SFML/Graphics.hpp>
#include <algorithm>
#include "IDisplay.hpp"

class DisplaySFML : public IDisplay {
public:
    DisplaySFML();
    ~DisplaySFML();

    /* window global */
    bool winOpen();
    void winClear();
    void winClose();
    void winInit();

    /* inputs */
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


    /* displays */
    void displayUsername(std::string &username);
    std::string usernameEntry(std::string &username);
    void displayMenu(std::string &game, std::vector<std::string> &userInfo);
    void displayScoreMenu(std::vector<std::string> &userInfo);
    void displayGame(std::vector<std::string> &map);

protected:
private:
    sf::RenderWindow _window;
    sf::Font _font;
    sf::Event _event;
    sf::Sprite _background;
    sf::Time _time;
    sf::Clock _clock;

    /* Username */
    sf::Texture _usernameBackground;
    sf::Text _usernameText;

    /* Menu */
    sf::Texture _menuBackground;
    sf::Text _menuGame;

    /* Games */
    sf::Texture _gameBackground;
    sf::Sprite _map;
    sf::Texture _W;
    sf::Texture _V;
    sf::Texture _P;
    sf::Texture _Q;
    sf::Texture _F;
    int _x;
    int _y;
};

#endif /* !DISPLAYSFML_HPP_ */
