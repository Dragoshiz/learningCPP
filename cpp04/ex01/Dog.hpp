#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	public:
		Dog();
		Dog(Dog const &);
		~Dog();
		Dog& operator=(Dog const &);
		void makeSound(void)const;
	private:
		Brain* _dogBrain;
};
#endif

