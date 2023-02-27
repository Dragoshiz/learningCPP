#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _wrongType("Wrong AAnimal"){
	std::cout << "\x1b[32mWrongAnimal default constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj){
	std::cout << "\x1b[33mWrongAnimal copy constructor called\033[0m" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "\x1b[31mWrongAnimal destructor called\033[0m" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &obj){
	std::cout << "\x1b[33mWrongAnimal copy assignment operator called\033[0m" << std::endl;
	this->_wrongType = obj._wrongType;
	return *this;
}

void WrongAnimal::makeSound(void)const{
	std::cout << "\x1b[33mWrong animal making a sound\033[0m" << std::endl;
}

std::string WrongAnimal::getType(void)const{
	return this->_wrongType;
}
