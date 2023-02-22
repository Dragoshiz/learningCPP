#include "ICharacter.hpp"

ICharacter::ICharacter(){
	std::cout << "\x1b[32mICharacter default constructor called\033[0m" << std::endl;
}

ICharacter::ICharacter(std::string name):_name(name){}

ICharacter::ICharacter(ICharacter const &obj){
	std::cout << "\x1b[33mICharacter copy constructor called\033[0m" << std::endl;
	*this = obj;
}

ICharacter::~ICharacter(){
	std::cout << "\x1b[31mICharacter destructor called\033[0m" << std::endl;
}

ICharacter& ICharacter::operator=(ICharacter const &obj){
	this->_name = obj._name;
	for (int i; i <4; i++)
		this->inventory[i] = obj.inventory[i];
	std::cout << "\x1b[33mICharacter copy assignment operator called\033[0m" << std::endl;
}

