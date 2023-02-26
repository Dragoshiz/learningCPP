#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("AAnimal"){
	std::cout << "\x1b[32mAAnimal default constructor called\033[0m" << std::endl;
}

AAnimal::AAnimal(AAnimal const &obj){
	std::cout << "\x1b[33mAAnimal copy constructor called\033[0m" << std::endl;
	*this = obj;
}

AAnimal::~AAnimal(){
	std::cout << "\x1b[31mAAnimal destructor called\033[0m" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const &obj){
	std::cout << "\x1b[33mAAnimal copy assignment operator called\033[0m" << std::endl;
	_type = obj._type;
	return *this;
}

void AAnimal::makeSound(void)const{
	std::cout << "\x1b[33mStandard animal sound\033[0m" << std::endl;
}

