#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "ICharacter.hpp"

class ICharacter;

class AMateria{
	public:
		AMateria();
		AMateria(AMateria const &);
		virtual ~AMateria();
		AMateria& operator=(AMateria const &);
		AMateria(std::string const &type);
		std::string const &getType(void)const;
		virtual AMateria* clone(void)const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string _type;
};
#endif
