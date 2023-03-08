#ifndef INTERN_HPP
#define INTERN_HPP
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern{
	public:
		Intern();
		Intern(Intern const &);
		~Intern();
		Intern& operator=(Intern const &);
		AForm* makeForm(std::string formtype, std::string targetForm);
		class FormNotFoundException: public std::exception{
			public:
				const char* what() const throw();
		};
};
#endif

