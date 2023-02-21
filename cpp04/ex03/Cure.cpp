#include "Cure.hpp"

Cure::Cure(){
	std::cout << "\x1b[32mCure default constructor called\033[0m" << std::endl;
}

Cure::Cure(Cure const &obj){
	std::cout << "\x1b[33mCure copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Cure::~Cure(){
	std::cout << "\x1b[31mCure destructor called\033[0m" << std::endl;
}

Cure& Cure::operator=(Cure const &obj){
	//assign obj to this variables!
	std::cout << "\x1b[33mCure copy assignment operator called\033[0m" << std::endl;
}

