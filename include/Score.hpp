/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <iostream>
#include <vector>
#include <fstream>

class Score {
	public:
		Score();
		~Score();

        void setConfig();
        std::vector<std::string> findUser(std::string &user);
        std::vector<std::string> explode(const std::string &str, const char &c);

	protected:
	private:
        std::vector<std::string> _config;
        std::string _user;
        int _line;
        std::string _game;
        std::vector<std::string> _userInfo;
};

#endif /* !SCORE_HPP_ */
