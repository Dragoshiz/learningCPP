#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	this->_dogBrain = new Brain();
	std::cout << "\x1b[32mDog default constructor called\033[0m" << std::endl;
}

Dog::Dog(Dog const &obj): Animal(obj){
	*this = obj;
	std::cout << "\x1b[33mDog copy constructor called\033[0m" << std::endl;
}

Dog::~Dog()
{
	delete this->_dogBrain;
	std::cout << "\x1b[31mDog destructor called\033[0m" << std::endl;
}

Dog& Dog::operator=(Dog const &obj){
	this->type = obj.type;
	this->_dogBrain = obj._dogBrain;
	std::cout << "\x1b[33mDog copy assignment operator called\033[0m" << std::endl;
	return *this;
}

void Dog::makeSound(void)const{
	std::cout << "\x1b[33mwof-wof\033[0m" << std::endl;
}

