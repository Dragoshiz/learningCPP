#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class AAnimal{
	public:
		AAnimal();
		AAnimal(AAnimal const &);
		virtual ~AAnimal();
		AAnimal& operator=(AAnimal const &);
		std::string getType(void)const{return this->type;};
		virtual void makeSound(void)const;
	protected:
		std::string type;
};
#endif
