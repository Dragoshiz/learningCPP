#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>

class Dog{
	public:
		Dog();
		Dog(Dog const &);
		~Dog();
		Dog& operator=(Dog const &);
	private:
};
#endif

