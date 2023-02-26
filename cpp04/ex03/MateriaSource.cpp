#include "MateriaSource.hpp"

MateriaSource::MateriaSource():_materiasCount(0){
	std::cout << "\x1b[32mMateriaSource default constructor called\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &obj): IMateriaSource(obj){
	std::cout << "\x1b[33mMateriaSource copy constructor called\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	*this = obj;
}

MateriaSource::~MateriaSource(){
	std::cout << "\x1b[31mMateriaSource destructor called\033[0m" << std::endl;
	for (int i = 0; i < _materiasCount; i++)
		delete _materias[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource const &obj){
	std::cout << "\x1b[33mMateriaSource copy assignment operator called\033[0m" << std::endl;
	for(int i = 0; i < 4; i++)
		_materias[i] = obj._materias[i]->clone();
	_materiasCount = obj._materiasCount;
	return *this;
}

void MateriaSource::learnMateria(AMateria* obj){
	std::cout << "\x1b[35mLearnMateria called\033[0m" << std::endl;
	if (_materiasCount >= 4)
	{
		delete obj;
		return;
	}
	_materias[_materiasCount++] = obj->clone();
	delete obj;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < _materiasCount; i++)
	{
		if (_materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	if (_materiasCount >= 4)
	{
		std::cout << "Not enough MateriaSource inventory full\n";
		return 0;
	}
	std::cout << "Needed to learn this Materia" << std::endl;
	return 0;
}

void MateriaSource::getMaterias(void){
	for(int i=0; i < _materiasCount; i++){
		std::cout << _materias[i]->getType() << "\n";
	}
}
