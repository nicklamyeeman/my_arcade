/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** OpenDir
*/

#include "OpenDir.hpp"

int OpenDir::findFile(std::string const &file) const
{
    int ret = -1;

    for (long unsigned int i = 0; i != _dirContent.size(); i++) {
        if (file.find(_dirContent.at(i)) != file.npos)
            ret = i;
    }
    return (ret);
}

bool OpenDir::parseContent(std::string const &path, std::string const &parse) const
{
    return (path.compare(0, parse.size(), parse.c_str()) == 0 &&
            path.compare(path.size() - 3, 3, ".so") == 0);
}

std::vector<std::string> OpenDir::getDirContent() const
{
    return (_dirContent);
}

OpenDir::OpenDir(std::string const &path, std::string const &parse)
{
    std::string tmp;
    DIR *dp = opendir(path.c_str());

    if (!dp)
        exit(EXIT_FAILURE);
    struct dirent *dptr = readdir(dp);
    for (int i = 0; dptr != nullptr; dptr = readdir(dp), i++) {
        tmp.assign(dptr->d_name);
        if (parseContent(tmp, parse))
            _dirContent.push_back(tmp);
    }
    closedir(dp);
}

OpenDir::~OpenDir()
{
}
