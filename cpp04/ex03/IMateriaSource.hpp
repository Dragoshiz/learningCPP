#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include <iostream>
#include "AMateria.hpp"

class IMateriaSource{
	public:
		IMateriaSource();
		IMateriaSource(IMateriaSource const &);
		~IMateriaSource();
		IMateriaSource& operator=(IMateriaSource const &);
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
#endif
