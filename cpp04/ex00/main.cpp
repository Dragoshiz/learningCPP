#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

	int main()
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		delete i;
		delete j;
		delete meta;
		const WrongAnimal* wrong = new WrongAnimal();
		const WrongAnimal* w_cat = new WrongCat();
		std::cout << wrong->getType() << " " << std::endl;
		std::cout << w_cat->getType() << " " << std::endl;
		wrong->makeSound();
		w_cat->makeSound();
		delete w_cat;
		delete wrong;
		return 0;
	}