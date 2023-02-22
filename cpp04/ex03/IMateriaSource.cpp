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
}

