#include "Intern.hpp"

Intern::Intern(){
	std::cout << "\x1b[32mIntern default constructor called\033[0m" << std::endl;
}

Intern::Intern(Intern const &obj){
	std::cout << "\x1b[33mIntern copy constructor called\033[0m" << std::endl;
	(void)obj;
	*this = obj;
}

Intern::~Intern(){
	std::cout << "\x1b[31mIntern destructor called\033[0m" << std::endl;
}

Intern& Intern::operator=(Intern const &obj){
	std::cout << "\x1b[33mIntern copy assignment operator called\033[0m" << std::endl;
	(void)obj;
	return *this;
}

AForm* Intern::makeForm(std::string formtype, std::string targetForm){


	std::string types[4]= {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while(formtype != types[i] && i < 3)
		i++;
	AForm *form = NULL;
	switch (i)
	{
	case 0:
		form = new ShrubberyCreationForm(targetForm);
		return form;
	case 1:
		form = new RobotomyRequestForm(targetForm);
		return form;
	case 2:
		form = new PresidentialPardonForm(targetForm);
		return form;
	default:
		throw(FormNotFoundException());
		break;
	}
	std::cout << "Intern creates " << types[i] << std::endl;
	return form;
}

const char * Intern::FormNotFoundException::what()const throw(){
	return "No form was found!";
}