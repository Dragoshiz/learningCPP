#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure: public AMateria{
	public:
		Cure();
		Cure(Cure const &);
		~Cure();
		Cure& operator=(Cure const &);
		AMateria* clone(void) const;
};
#endif
