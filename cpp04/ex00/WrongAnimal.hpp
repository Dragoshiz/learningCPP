#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(WrongAnimal const &);
		std::string getType(void)const{return this->wrongType;};
		virtual void makeSound(void)const;
	protected:
		std::string wrongType;
};
#endif

