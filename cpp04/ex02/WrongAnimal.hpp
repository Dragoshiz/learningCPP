#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAAnimal{
	public:
		WrongAAnimal();
		WrongAAnimal(WrongAAnimal const &);
		virtual ~WrongAAnimal();
		WrongAAnimal& operator=(WrongAAnimal const &);
		std::string getType(void)const{return this->wrongType;};
		virtual void makeSound(void)const;
	protected:
		std::string wrongType;
};
#endif

