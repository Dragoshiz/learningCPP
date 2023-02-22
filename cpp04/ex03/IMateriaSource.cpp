#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(){
	std::cout << "\x1b[32mIMateriaSource default constructor called\033[0m" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &obj){
	std::cout << "\x1b[33mIMateriaSource copy constructor called\033[0m" << std::endl;
	*this = obj;
}

IMateriaSource::~IMateriaSource(){
	std::cout << "\x1b[31mIMateriaSource destructor called\033[0m" << std::endl;
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource const &obj){
	std::cout << "\x1b[33mIMateriaSource copy assignment operator called\033[0m" << std::endl;
	(void)obj;
	return *this;
}

// void IMateriaSource::learnMateria(AMateria* obj){
// 	if (this->_materiasCount >= 4)
// 		return;
// 	this->_materias[this->_materiasCount++] = obj;
// 	std::cout << "\x1b[35mLearnMateria called\033[0m" << std::endl;
// }

// AMateria* IMateriaSource::createMateria(std::string const & type){
// 	for (int i = 0; this->_materias[i]; i++)
// 	{
// 		if (this->_materias[i]->getType() == type)
// 			return this->_materias[i];
// 	}
// 	std::cout << "Needed to learn this Materia" << std::endl;
// 	return 0;
// }