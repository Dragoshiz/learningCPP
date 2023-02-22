#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &);
		~MateriaSource();
		MateriaSource& operator=(MateriaSource const &);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	private:
		AMateria	*_materias[4];
		int			_materiasCount;
};
#endif

