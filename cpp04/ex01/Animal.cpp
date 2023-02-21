#include "Animal.hpp"

AAnimal::AAnimal(): type("Animal"){
	std::cout << "\x1b[32mAnimal default constructor called\033[0m" << std::endl;
}

AAnimal::AAnimal(AAnimal const &obj){
	*this = obj;
	std::cout << "\x1b[33mAnimal copy constructor called\033[0m" << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "\x1b[31mAnimal destructor called\033[0m" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const &obj){
	type = obj.type;
	std::cout << "\x1b[33mAnimal copy assignment operator called\033[0m" << std::endl;
	return *this;
}

void AAnimal::makeSound(void)const{
	std::cout << "\x1b[33mStandard animal sound\033[0m" << std::endl;
}

