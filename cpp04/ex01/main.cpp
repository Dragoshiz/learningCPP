#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		Animal zanimal;
		zanimal.makeSound();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		i->makeSound();
		j->makeSound();
		delete j;
		delete i;
	}

	{
		std::cout << "===========NEXT PHASE===========" << std::endl;
		Dog *dog = new Dog();
		Dog doggo;
		Cat *cat = new Cat();
		Cat cat2;
		dog->setIdea("stupid");
		dog->setIdea("hello world");
		dog->getIdeas();
		cat->setIdea("littering");
		cat->setIdea("hello");
		cat2 = *cat;
		delete cat;
		cat2.getIdeas();
		doggo = *dog;
		dog->getIdeas();
		doggo.getIdeas();
		delete dog;
		doggo.getIdeas();

	}
	return 0;
}