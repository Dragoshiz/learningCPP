#include "Cat.hpp"

Cat::Cat():_catBrain(new Brain()){
	this->type = "Cat";
	std::cout << "\x1b[32mCat default constructor called\033[0m" << std::endl;
}

Cat::Cat(Cat const &obj): AAnimal(obj){
	*this = obj;
	std::cout << "\x1b[33mCat copy constructor called\033[0m" << std::endl;
}

Cat::~Cat(){
	delete this->_catBrain;
	std::cout << "\x1b[31mCat destructor called\033[0m" << std::endl;
}

Cat& Cat::operator=(Cat const &obj){
	this->_catBrain = obj._catBrain;
	this->type = obj.type;
	std::cout << "\x1b[33mCat copy assignment operator called\033[0m" << std::endl;
	return *this;
}

void Cat::makeSound(void)const{
	std::cout << "\x1b[33mMiau\033[0m" << std::endl;
}