#include "AMateria.hpp"

AMateria::AMateria(){
	std::cout << "\x1b[32mAMateria default constructor called\033[0m" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type){
	std::cout << "\x1b[32mAMateria name constructor called\033[0m" << std::endl;
}
AMateria::AMateria(AMateria const &obj){
	std::cout << "\x1b[33mAMateria copy constructor called\033[0m" << std::endl;
	*this = obj;
}

AMateria::~AMateria(){
	std::cout << "\x1b[31mAMateria destructor called\033[0m" << std::endl;
}

AMateria& AMateria::operator=(AMateria const &obj){
	if(this != &obj){
		this->_type = obj._type;
		std::cout << "\x1b[33mAMateria copy assignment operator called\033[0m" << std::endl;
	}
	return *this;
}

std::string const &AMateria::getType(void)const{
	return this->_type;
}

// void AMateria::setType(std::string const &type){
// 	this->_type = type;
// }