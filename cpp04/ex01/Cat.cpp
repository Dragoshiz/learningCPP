#include "Cat.hpp"

Cat::Cat():_catBrain(new Brain()){
	this->_type = "Cat";
	std::cout << "\x1b[32mCat default constructor called\033[0m" << std::endl;
}

Cat::Cat(Cat const &obj): Animal(obj){
	std::cout << "\x1b[33mCat copy constructor called\033[0m" << std::endl;
}

Cat::~Cat(){
	std::cout << "\x1b[31mCat destructor called\033[0m" << std::endl;
	delete _catBrain;
}

Cat& Cat::operator=(Cat const &obj){
	*_catBrain = *obj._catBrain;
	_type = obj._type;
	std::cout << "\x1b[33mCat copy assignment operator called\033[0m" << std::endl;
	return *this;
}

void Cat::setIdea(std::string idea){
	_catBrain->setIdeas(idea);
}

void Cat::getIdeas(void){
	_catBrain->getIdeas();
}

void Cat::makeSound(void)const{
	std::cout << "\x1b[33mMiau\033[0m" << std::endl;
}