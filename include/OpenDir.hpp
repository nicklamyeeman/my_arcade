/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** OpenDir
*/

#ifndef OPENDIR_HPP_
#define OPENDIR_HPP_

#include <iostream>
#include <vector>
#include <sys/types.h>
#include <dirent.h>

class OpenDir {
	public:
		OpenDir(std::string const &path, std::string const &parse);
		~OpenDir();

        /* Getters */
        std::vector<std::string> getDirContent() const;
        int findFile(std::string const &file) const;
  
	protected:
        bool parseContent(std::string const &path, std::string const &parse) const;
	private:
        std::vector<std::string> _dirContent;
};

#endif /* !OPENDIR_HPP_ */
