#include "Brain.hpp"

Brain::Brain(){
	std::cout << "\x1b[32mBrain default constructor called\033[0m" << std::endl;
}

Brain::Brain(Brain const &obj){
	std::cout << "\x1b[33mBrain copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Brain::~Brain(){
	std::cout << "\x1b[31mBrain destructor called\033[0m" << std::endl;
}

Brain& Brain::operator=(Brain const &obj){
	for(int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	std::cout << "\x1b[33mBrain copy assignment operator called\033[0m" << std::endl;
	return *this;
}

