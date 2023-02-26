#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"


int main()
{
	{
		std::cout << "\x1B[34m" << "\n##### MY TEST #####\n" << "\x1B[0m" << std::endl;
		IMateriaSource* src = new MateriaSource();
		std::cout << "\n### LEARN 5 Materias (one too much) ###" << std::endl;
		
		for (int i = 0; i < 5; i++)
			src->learnMateria(new Ice());
		
		std::cout << "\n### CREATE new Character ###" << std::endl;
		
		Character* me = new Character("me");
		AMateria* tmp;
		
		std::cout << "\n### EQUIP 5 Materias (one too much) ###" << std::endl;
		
		for (int i = 0; i < 5; i++)
		{
			tmp = src->createMateria("ice");
			me->equip(tmp);
		}
		delete tmp;
		
		std::cout << "\n### CREATE new Character ###" << std::endl;
		
		Character *bob = new Character("bob");
		*bob = *me;

		delete me;
		ICharacter *santa = new Character("santa");
		std::cout << "\n### USE 5 Materias (one too much) ###" << std::endl;
		bob->use(0, *santa);
		bob->use(1, *santa);
		bob->use(2, *santa);
		bob->use(3, *santa);
		bob->use(4, *santa);
		std::cout << "\n### Starting destruction... ###" << std::endl;
		delete src;
		delete santa;
		delete bob;
		return 0;
	}
}