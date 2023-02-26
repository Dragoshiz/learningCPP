#include "Animal.hpp"

Animal::Animal(): type("Animal"){
	std::cout << "\x1b[32mAnimal default constructor called\033[0m" << std::endl;
}

Animal::Animal(Animal const &obj){
	std::cout << "\x1b[33mAnimal copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Animal::~Animal(){
	std::cout << "\x1b[31mAnimal destructor called\033[0m" << std::endl;
}

Animal& Animal::operator=(Animal const &obj){
	std::cout << "\x1b[33mAnimal copy assignment operator called\033[0m" << std::endl;
	type = obj.type;
	return *this;
}

void Animal::makeSound(void)const{
	std::cout << "\x1b[33mStandard animal sound\033[0m" << std::endl;
}

