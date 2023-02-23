#include "MateriaSource.hpp"

MateriaSource::MateriaSource():_materiasCount(0){
	std::cout << "\x1b[32mMateriaSource default constructor called\033[0m" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &obj): IMateriaSource(obj){
	std::cout << "\x1b[33mMateriaSource copy constructor called\033[0m" << std::endl;
	*this = obj;
}

MateriaSource::~MateriaSource(){
	std::cout << "\x1b[31mMateriaSource destructor called\033[0m" << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource const &obj){
	std::cout << "\x1b[33mMateriaSource copy assignment operator called\033[0m" << std::endl;
	for(int i = 0; obj._materias[i]; i++)
		this->_materias[i] = obj._materias[i];
	this->_materiasCount = obj._materiasCount;
	return *this;
}

void MateriaSource::learnMateria(AMateria* obj){
	std::cout << "\x1b[35mLearnMateria called\033[0m" << std::endl;
	if (this->_materiasCount >= 4)
		return;
	this->_materias[this->_materiasCount++] = obj;
	delete obj;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; this->_materias[i]; i++)
	{
		if (this->_materias[i]->getType() == type)
			return this->_materias[i];
	}
	std::cout << "Needed to learn this Materia" << std::endl;
	return 0;
}

void MateriaSource::getMaterias(void){
	for(int i=0; this->_materias[i]; i++){
		std::cout << this->_materias[i]->getType() << "\n";
	}
	std::cout << std::endl;
}
