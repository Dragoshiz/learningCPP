#include "WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << "\x1b[32mWrongCat default constructor called\033[0m" << std::endl;
	this->wrongType = "Wrong cat";
}

WrongCat::WrongCat(WrongCat const &obj): WrongAAnimal(obj){
	std::cout << "\x1b[33mWrongCat copy constructor called\033[0m" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat(){
	std::cout << "\x1b[31mWrongCat destructor called\033[0m" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &obj){
	std::cout << "\x1b[33mWrongCat copy assignment operator called\033[0m" << std::endl;
	this->wrongType = obj.wrongType;
	return *this;
}

void WrongCat::makeSound(void)const{
	std::cout << "\x1b[33mWrong cat sound muuuuu\033[0m" << std::endl;
}
