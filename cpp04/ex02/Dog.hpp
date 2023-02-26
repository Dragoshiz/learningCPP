#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal{
	public:
		Dog();
		Dog(Dog const &);
		~Dog();
		Dog& operator=(Dog const &);
		void makeSound(void)const;
		void setIdea(std::string idea);
		void getIdeas(void);
	private:
		Brain*	_dogBrain;
};
#endif

