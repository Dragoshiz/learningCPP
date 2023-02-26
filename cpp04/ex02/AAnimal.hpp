#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <iostream>

class AAnimal{
	public:
		AAnimal();
		AAnimal(AAnimal const &);
		virtual ~AAnimal();
		AAnimal& operator=(AAnimal const &);
		std::string getType(void)const{return this->_type;};
		virtual void makeSound(void)const = 0;
	protected:
		std::string _type;
};
#endif

