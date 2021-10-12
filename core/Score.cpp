/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Score
*/

#include "Score.hpp"

std::vector<std::string> Score::explode(const std::string &s, const char &c)
{
    std::string buff = "";
    std::vector<std::string> v;

    for(auto n : s) {
        if (n != c)
            buff += n;
        else if (n == c && buff != "") {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
        v.push_back(buff);
    return (v);
}

std::vector<std::string> Score::findUser(std::string &user)
{
    for (int i = 0; i != (int)_config.size(); i++) {
        if (_config.at(i).compare(0, user.size() - 1, user.c_str(), 0, user.size() - 1) == 0) {
            _user.assign(_config.at(i));
            _line = i;
        }
    }
    if (!_user.empty())
        _userInfo = explode(_config.at(_line), ':');
    else
        _userInfo.push_back(_user);
    return (_userInfo);
}

void Score::setConfig()
{
    std::ifstream file("./.config");
    std::string tmp;

 	if (!file.is_open())
        return;
    while (std::getline(file, tmp)) {
        if (tmp.empty())
            continue;
        _config.push_back(tmp);
    }
    file.close();
}

Score::Score()
{
    setConfig();
}

Score::~Score()
{
}
