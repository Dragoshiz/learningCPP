#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(RobotomyRequestForm const &);
		void execute(Bureaucrat const & executor) const;
};
#endif

