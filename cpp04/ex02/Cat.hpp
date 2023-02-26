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
		void setIdea(std::string idea);
		void getIdeas(void);
	private:
		Brain*	_catBrain;
};
#endif
