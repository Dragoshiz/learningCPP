#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include "AMateria.hpp"

class ICharacter{
	public:
		ICharacter();
		ICharacter(ICharacter const &);
		virtual ~ICharacter(){};
		ICharacter& operator=(ICharacter const &);
		virtual std::string const & getName(void)const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};
#endif
