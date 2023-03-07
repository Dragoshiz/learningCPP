#include "AForm.hpp"

AForm::AForm(): _name("The no named AForm"), _grade2sign(50),  _grade2exec(50), _is_signed(false), _target("no target"){
	std::cout << "\x1b[32mAForm default constructor called\033[0m" << std::endl;
}

AForm::AForm(std::string name, int grade2sign, int grade2exec, bool is_signed, std::string target):
_name(name), _grade2sign(this->setGrade2sign(grade2sign)), _grade2exec(this->setGrade2exec(grade2exec)), _is_signed(is_signed), _target(target)
{
	std::cout << "\x1b[32mAForm name constructor called\033[0m" << std::endl;
}
AForm::AForm(AForm const &obj):
_name(obj._name), _grade2sign(obj._grade2sign), _grade2exec(obj._grade2exec), _is_signed(obj._is_signed), _target(obj._target)
{
	std::cout << "\x1b[33mAForm copy constructor called\033[0m" << std::endl;
}

AForm::~AForm(){
	std::cout << "\x1b[31mAForm destructor called\033[0m" << std::endl;
}

AForm& AForm::operator=(AForm const &obj){
	std::cout << "\x1b[33mAForm copy assignment operator called\033[0m" << std::endl;
	_is_signed = obj._is_signed;
	setGrade2exec(obj.getGrade2exec());
	setGrade2sign(obj.getGrade2sign());
	_target = obj.getTarget();
	return *this;
}

int		AForm::setGrade2exec(int gradeExec){
	try{
		if (gradeExec < 1)
			throw(GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try{
		if (gradeExec > 150)
			throw(GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return gradeExec;
}

int		AForm::setGrade2sign(int gradeSign){
	try{
		if (gradeSign < 1)
			throw(GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try{
		if (gradeSign > 150)
			throw(GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return gradeSign;
}

std::string AForm::getName(void)const{
	return _name;
}

bool AForm::isSigned(void)const{
	return _is_signed;
}

int AForm::getGrade2sign(void)const{
	return _grade2sign;
}

int AForm::getGrade2exec(void)const{
	return _grade2exec;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, AForm const &obj){
	return out << "The AForm's name: " << obj.getName() << "\nsigned :" << obj.isSigned() << "\ngrade to sign: " << obj.getGrade2sign() << "\ngrade to execute: " << obj.getGrade2exec() << std::endl;
}

void AForm::beSigned(Bureaucrat &obj){
	if (obj.getGrade() <= this->_grade2sign)
		this->_is_signed = true;
	else
		throw(GradeTooLowException());
}

void AForm::setSigned(bool sign){
	this->_is_signed = sign;
}

std::string AForm::getTarget(void)const{
	return _target;
}