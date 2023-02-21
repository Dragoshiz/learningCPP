#ifndef CAT_HPP
#define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal{
	public:
		Cat();
		Cat(Cat const &);
		~Cat();
		Cat& operator=(Cat const &);
		void makeSound(void)const;
	private:
		Brain*	_catBrain;
};
#endif

