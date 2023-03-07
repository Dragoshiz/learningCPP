#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

	class PresidentialPardonForm: public AForm{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(PresidentialPardonForm const &);
		void execute(Bureaucrat const & executor) const;
};
#endif

