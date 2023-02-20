#include "Dog.hpp"

Dog::Dog(){
	std::cout << "\x1b[32mDefault constructor called\033[0m" << std::endl;
}

Dog::Dog(Dog const &obj){
	std::cout << "\x1b[33mCopy constructor called\033[0m" << std::endl;
}

Dog::~Dog(){
	std::cout << "\x1b[31mDestructor called\033[0m" << std::endl;
}

Dog& Dog::operator=(Dog const &obj){
	//assign obj to this variables!
	std::cout << "\x1b[33mCopy assignment operator called\033[0m" << std::endl;
}

