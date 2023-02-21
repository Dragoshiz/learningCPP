#include "Ice.hpp"

Ice::Ice(){
	std::cout << "\x1b[32mIce default constructor called\033[0m" << std::endl;
}

Ice::Ice(Ice const &obj){
	std::cout << "\x1b[33mIce copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Ice::~Ice(){
	std::cout << "\x1b[31mIce destructor called\033[0m" << std::endl;
}

Ice& Ice::operator=(Ice const &obj){
	//assign obj to this variables!
	std::cout << "\x1b[33mIce copy assignment operator called\033[0m" << std::endl;
}

