#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAAnimal{
	public:
		WrongCat();
		WrongCat(WrongCat const &);
		~WrongCat();
		WrongCat& operator=(WrongCat const &);
		void makeSound(void)const;
};
#endif

