#include "WrongAnimal.hpp"

WrongAAnimal::WrongAAnimal(): wrongType("Wrong AAnimal"){
	std::cout << "\x1b[32mWrongAnimal default constructor called\033[0m" << std::endl;
}

WrongAAnimal::WrongAAnimal(WrongAAnimal const &obj){
	std::cout << "\x1b[33mWrongAnimal copy constructor called\033[0m" << std::endl;
	*this = obj;
}

WrongAAnimal::~WrongAAnimal(){
	std::cout << "\x1b[31mWrongAnimal destructor called\033[0m" << std::endl;
}

WrongAAnimal& WrongAAnimal::operator=(WrongAAnimal const &obj){
	std::cout << "\x1b[33mWrongAnimal copy assignment operator called\033[0m" << std::endl;
	this->wrongType = obj.wrongType;
	return *this;
}

void WrongAAnimal::makeSound(void)const{
	std::cout << "\x1b[33mWrong animal making a sound\033[0m" << std::endl;
}
