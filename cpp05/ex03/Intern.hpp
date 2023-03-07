#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"

class Intern{
	public:
		Intern();
		Intern(Intern const &);
		~Intern();
		Intern& operator=(Intern const &);
		AForm& makeForm(std::string formtype, std::string targetForm);
	private:
};
#endif

