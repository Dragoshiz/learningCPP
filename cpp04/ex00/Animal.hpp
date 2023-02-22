#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal{
	public:
		Animal();
		Animal(Animal const &);
		virtual ~Animal();
		Animal& operator=(Animal const &);
		std::string getType(void)const{return this->type;};
		virtual void makeSound(void)const;
	protected:
		std::string type;
};
#endif
