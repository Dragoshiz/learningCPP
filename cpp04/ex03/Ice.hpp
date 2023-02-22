#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice: public AMateria{
	public:
		Ice();
		Ice(Ice const &);
		~Ice();
		Ice& operator=(Ice const &);
		AMateria* clone(void)const;
		// void use(ICharacter& target) override;
};
#endif

