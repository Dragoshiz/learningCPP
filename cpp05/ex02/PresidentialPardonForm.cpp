#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("The no name PresidentialPardonForm", 25, 5, false, "no target")
{
	std::cout << "\x1b[32mPresidentialPardonForm default constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("The no name PresidentialPardonForm", 25, 5, false, target)
{
	std::cout << "\x1b[32mPresidentialPardonForm default constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj):
AForm(obj.getName(), obj.getGrade2sign(), obj.getGrade2exec(), obj.isSigned(), obj.getTarget())
{
	std::cout << "\x1b[33mPresidentialPardonForm copy constructor called\033[0m" << std::endl;
	this->setGrade2exec(obj.getGrade2exec());
	this->setGrade2sign(obj.getGrade2sign());
	this->setSigned(obj.isSigned());
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "\x1b[31mPresidentialPardonForm destructor called\033[0m" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &obj){
	std::cout << "\x1b[33mPresidentialPardonForm copy assignment operator called\033[0m" << std::endl;
	this->setGrade2exec(obj.getGrade2exec());
	this->setGrade2sign(obj.getGrade2sign());
	this->setSigned(obj.isSigned());
	return *this;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	(void)executor;
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}