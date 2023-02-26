#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"

class Character: public ICharacter{
	public:
		Character();
		Character(Character const &);
		Character(std::string name);
		~Character();
		Character& operator=(Character const &);
		std::string const & getName(void)const;
		void use(int idx, ICharacter& target);
		void unequip(int idx);
		void equip(AMateria* m);
		void getMaterias(void);
	private:
		std::string	_name;
		AMateria*	_inventory[4];
};
#endif

