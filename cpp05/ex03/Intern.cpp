#include "Intern.hpp"

Intern::Intern(){
	std::cout << "\x1b[32mIntern default constructor called\033[0m" << std::endl;
}

Intern::Intern(Intern const &obj){
	std::cout << "\x1b[33mIntern copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Intern::~Intern(){
	std::cout << "\x1b[31mIntern destructor called\033[0m" << std::endl;
}

Intern& Intern::operator=(Intern const &obj){
	//assign obj to this variables!
	std::cout << "\x1b[33mIntern copy assignment operator called\033[0m" << std::endl;
}

AForm& Intern::makeForm(std::string formtype, std::string targetForm){

	std::string types[3]= {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 4; i++)
		if (formtype == types[i])
			break;
	if(	)
}