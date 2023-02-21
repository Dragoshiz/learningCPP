#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// AAnimal  zaanimal; //this will not work
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	i->makeSound();
	j->makeSound();
	delete j;
	delete i;

	std::cout << "===========NEXT PHASE===========" << std::endl;
	const AAnimal* animals[10];
	for(int index =0; index < 10; index++)
	{
		if (index < 5)
			animals[index] = new Dog;
		else
			animals[index] = new Cat;
	}
	for(int index2 = 0; index2 < 10; index2++)
	{
		if (index2 < 5)
			delete animals[index2];
		else
			delete animals[index2];
	}
	return 0;
}