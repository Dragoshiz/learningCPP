#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "====Main from subject====" << std::endl;
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
	}

	{
		std::cout << "===Main for wrong animals===" << std::endl;
		const WrongAnimal* wrong = new WrongAnimal();
		const WrongAnimal* wrong_cat = new WrongAnimal();
		const WrongCat* w_cat = new WrongCat();
		std::cout << wrong->getType() << std::endl;
		std::cout << wrong_cat->getType() << std::endl;
		std::cout << w_cat->getType() << std::endl;
		wrong->makeSound();
		wrong_cat->makeSound();
		w_cat->makeSound();
		delete w_cat;
		delete wrong_cat;
		delete wrong;
		return 0;
	}
}