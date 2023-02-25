#include "Dog.hpp"

Dog::Dog(){
	std::cout << "\x1b[32mDog default constructor called\033[0m" << std::endl;
	_type = "Dog";
	_dogBrain = new Brain();
}

Dog::Dog(Dog const &obj): Animal(obj){
	std::cout << "\x1b[33mDog copy constructor called\033[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		_dogBrain[i] = obj._dogBrain[i];
}

Dog::~Dog()
{
	std::cout << "\x1b[31mDog destructor called\033[0m" << std::endl;
	delete this->_dogBrain;
}

Dog& Dog::operator=(Dog const &obj){
	std::cout << "\x1b[33mDog copy assignment operator called\033[0m" << std::endl;
		*_dogBrain= *obj._dogBrain;
	return *this;
}

void Dog::makeSound(void)const{
	std::cout << "\x1b[33mwof-wof\033[0m" << std::endl;
}

void Dog::setIdea(std::string idea){
	_dogBrain->setIdeas(idea);
}

void Dog::getIdeas(void){
	_dogBrain->getIdeas();
}
