#include "Dog.hpp"

Dog::Dog(){
	std::cout << "\x1b[32mDog default constructor called\033[0m" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &obj): Animal(obj){
	std::cout << "\x1b[33mDog copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Dog::~Dog(){
	std::cout << "\x1b[31mDog destructor called\033[0m" << std::endl;
}

Dog& Dog::operator=(Dog const &obj){
	std::cout << "\x1b[33mDog copy assignment operator called\033[0m" << std::endl;
	this->type = obj.type;
	return *this;
}

void Dog::makeSound(void)const{
	std::cout << "\x1b[33mwof-wof\033[0m" << std::endl;
}

