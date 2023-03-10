#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("The one with no name"), _grade(150){
	std::cout << "\x1b[32mBureaucrat default constructor called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj):
_name(obj._name), _grade(obj._grade)
{
	std::cout << "\x1b[33mBureaucrat copy constructor called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150){
	std::cout << "\x1b[33mBureaucrat name constructor called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(this->setGrade(grade)){
	std::cout << "\x1b[33mBureaucrat name constructor called\033[0m" << std::endl;
}
Bureaucrat::~Bureaucrat(){
	std::cout << "\x1b[31mBureaucrat destructor called\033[0m" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &obj){
	std::cout << "\x1b[33mBureaucrat copy assignment operator called\033[0m" << std::endl;
	new (this) Bureaucrat(obj._name);
	_grade = obj.getGrade();
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& obj){
	return out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
}

std::string Bureaucrat::getName(void)const{
	return _name;
}

int		Bureaucrat::getGrade(void)const{
	return _grade;
}
const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

int	Bureaucrat::setGrade(int grade){
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
	return grade;
}

void Bureaucrat::increment(void){
	setGrade(_grade - 1);
}

void	 Bureaucrat::decrement(void){
	setGrade(_grade + 1);
}
