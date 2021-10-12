/*
** EPITECH PROJECT, 2019
** graphic
** File description:
** DisplaySFML
*/

#include "DisplaySFML.hpp"

bool DisplaySFML::pressPrevLib()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::F2));
}

bool DisplaySFML::pressNextLib()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::F3));
}

bool DisplaySFML::pressPrevGame()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::F4));
}

bool DisplaySFML::pressNextGame()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::F5));
}

bool DisplaySFML::pressRestartGame()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete));
}

bool DisplaySFML::pressBackMenu()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::B));
}

bool DisplaySFML::pressQuit()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
}

bool DisplaySFML::pressEnter()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
}

bool DisplaySFML::pressForward()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
}

bool DisplaySFML::pressLeft()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
}

bool DisplaySFML::pressBackward()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::S));
}

bool DisplaySFML::pressRight()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::D));
}

bool DisplaySFML::pressIn()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::K));
}

bool DisplaySFML::pressOut()
{
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::P));
}

void DisplaySFML::displayGame(std::vector<std::string> &map)
{
    int x = _x;
    int y = _y;
    std::string tmp;

    _background.setTexture(_gameBackground);
    _window.draw(_background);
    for (int i = 0; (int)map.size() != i; i++) {
        tmp = map.at(i);
        for (char a : tmp) {
            if (a == 'W')
                _map.setTexture(_W);
            if (a == 'V')
                _map.setTexture(_V);
            if (a == 'P')
                _map.setTexture(_P);
            if (a == 'Q')
                _map.setTexture(_Q);
            if (a == 'F')
                _map.setTexture(_F);
            _map.setPosition(x, y);
            x += 53;
            _window.draw(_map);
        }
        x = _x;
        y += 53;
    }
}

void DisplaySFML::displayScoreMenu(std::vector<std::string> &userInfo)
{
    (void)userInfo;
}

void DisplaySFML::displayMenu(std::string &game, std::vector<std::string> &userInfo)
{
    _menuGame.setString(game.c_str() + 11);
    _menuGame.setFont(_font);
    _menuGame.setStyle(_menuGame.Bold);
    _menuGame.setCharacterSize(80);
    _menuGame.setPosition(400, 330);

    _background.setTexture(_menuBackground);

    _window.draw(_background);
    _window.draw(_menuGame);
    displayScoreMenu(userInfo);
}

void DisplaySFML::displayUsername(std::string &username)
{
    _usernameText.setString(username);
    _usernameText.setFont(_font);
    _usernameText.setStyle(_usernameText.Bold);
    _usernameText.setCharacterSize(80);
    _usernameText.setPosition(400, 330);

    _background.setTexture(_usernameBackground);

    _window.draw(_background);
    _window.draw(_usernameText);
}

std::string DisplaySFML::usernameEntry(std::string &username)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::TextEntered) {
            if (_event.text.unicode == 8 && username.size() > 0)
                username.pop_back();
            else
                username += (char)_event.text.unicode;
        }
    }
    displayUsername(username);
    return (username);
}

void DisplaySFML::winInit()
{
    _window.setKeyRepeatEnabled(false);
    _font.loadFromFile("./assets/fonts/font.ttf");

    /* Username */
    _usernameBackground.loadFromFile("./assets/backgrounds/username_bg.png");
    /* Menu */
    _menuBackground.loadFromFile("./assets/backgrounds/menu_bg.png");
    /* Game */
    _gameBackground.loadFromFile("./assets/backgrounds/game_bg.png");
}

void DisplaySFML::winClose()
{
    _window.close();
}

bool DisplaySFML::winOpen()
{
    return (_window.isOpen());
}

void DisplaySFML::winClear()
{
    for (int i = 0; i != 200000; i++);
    _window.display();
    _window.clear();
}

DisplaySFML::DisplaySFML() : _window(sf::VideoMode(1080, 720), "SFML window")
{
    _W.loadFromFile("./assets/textures/W.png");
    _V.loadFromFile("./assets/textures/V.png");
    _P.loadFromFile("./assets/textures/P.png");
    _Q.loadFromFile("./assets/textures/Q.png");
    _F.loadFromFile("./assets/textures/F.png");
    _x = 145;
    _y = 111;
}

DisplaySFML::~DisplaySFML()
{
}

extern "C" {
    IDisplay *startingBlock() {
        return (new DisplaySFML());
    }
}
