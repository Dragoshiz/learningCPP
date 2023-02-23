#include "ICharacter.hpp"

ICharacter::ICharacter(){
	std::cout << "\x1b[32mICharacter default constructor called\033[0m" << std::endl;
}

ICharacter::ICharacter(ICharacter const &obj){
	std::cout << "\x1b[33mICharacter copy constructor called\033[0m" << std::endl;
	*this = obj;
}

ICharacter::~ICharacter(){
	std::cout << "\x1b[31mICharacter destructor called\033[0m" << std::endl;
}

ICharacter& ICharacter::operator=(ICharacter const &obj){
	std::cout << "\x1b[33mICharacter copy assignment operator called\033[0m" << std::endl;
	(void)obj;
	return *this;
}
