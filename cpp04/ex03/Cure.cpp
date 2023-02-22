#include "Cure.hpp"

Cure::Cure(){
	this->_type = "cure";
	std::cout << "\x1b[32mCure default constructor called\033[0m" << std::endl;
}

Cure::Cure(Cure const &obj): AMateria(obj){
	std::cout << "\x1b[33mCure copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Cure::~Cure(){
	std::cout << "\x1b[31mCure destructor called\033[0m" << std::endl;
}

Cure& Cure::operator=(Cure const &obj){
	std::cout << "\x1b[33mCure copy assignment operator called\033[0m" << std::endl;
	this->_type = obj._type;
	return *this;
}

AMateria* Cure::clone(void)const{
	return new Cure(*this);
}

// void Cure::use(ICharacter& target){
// 	std::cout << "* heals " + target.getName() + "'s wounds *" << std::endl;
// }
