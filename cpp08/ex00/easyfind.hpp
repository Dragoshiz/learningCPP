#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class ValueNotFoundExeption:public std::exception{
	const char* what() const throw(){
		return "Value not found!";
	};
};

template <typename T>
int easyFind(T &container, int to_find){
	if (std::find(container.begin(), container.end(), to_find) != container.end())
		return to_find;
	throw(ValueNotFoundExeption());
}

#endif
