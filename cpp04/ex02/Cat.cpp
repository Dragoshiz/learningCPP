#include "Cat.hpp"

Cat::Cat():_catBrain(new Brain()){
	std::cout << "\x1b[32mCat default constructor called\033[0m" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const &obj): AAnimal(obj){
	std::cout << "\x1b[33mCat copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Cat::~Cat(){
	std::cout << "\x1b[31mCat destructor called\033[0m" << std::endl;
	delete _catBrain;
}

Cat& Cat::operator=(Cat const &obj){
	std::cout << "\x1b[33mCat copy assignment operator called\033[0m" << std::endl;
	*_catBrain = *obj._catBrain;
	_type = obj._type;
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