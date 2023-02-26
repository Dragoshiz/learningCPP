#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "===========Same as before===========" << std::endl;
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
		std::cout << "===========Custom main===========" << std::endl;
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

	{
		std::cout << "====Showing correct constructor-destructor calls====" << std::endl;
		Animal *animals[10];
		for(int i=0; i < 10; i++)
		{
			if (i < 5)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for(int i=0; i< 10; i++)
			delete animals[i];
	}
	return 0;
}
