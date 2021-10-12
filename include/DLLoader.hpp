/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <iostream>
#include <dlfcn.h>

template <class T>
class DLLoader {
	public:
        /* Getter */
        T openLib(std::string &path);

        /* Setter */
        void closeLib();

	protected:
	private:
        void *_handle;
};

template <class T>
T DLLoader<T>::openLib(std::string &path)
{
    T (*dlFunc)();
    T dlib;

    _handle = dlopen(path.c_str(), RTLD_NOW);
    if (!_handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    dlFunc = (T (*)())dlsym(_handle, "startingBlock");
    dlib = dlFunc();
    return (dlib);
}

template <class T>
void DLLoader<T>::closeLib()
{
    dlclose(_handle);
}

#endif /* !DLLOADER_HPP_ */
