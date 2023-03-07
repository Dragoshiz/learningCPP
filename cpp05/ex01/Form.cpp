#include "Form.hpp"

Form::Form(): _name("The no named form"), _grade2sign(50),  _grade2exec(50), _is_signed(false){
	std::cout << "\x1b[32mForm default constructor called\033[0m" << std::endl;
}

Form::Form(std::string name, int grade2sign, int grade2exec, bool is_signed):
_name(name), _grade2sign(this->setGrade2sing(grade2sign)), _grade2exec(this->setGrade2exec(grade2exec)), _is_signed(is_signed)
{
	std::cout << "\x1b[32mForm name constructor called\033[0m" << std::endl;
}
Form::Form(Form const &obj):
_name(obj._name), _grade2sign(obj._grade2sign), _grade2exec(obj._grade2exec), _is_signed(obj._is_signed)
{
	std::cout << "\x1b[33mForm copy constructor called\033[0m" << std::endl;
}

Form::~Form(){
	std::cout << "\x1b[31mForm destructor called\033[0m" << std::endl;
}

Form& Form::operator=(Form const &obj){
	std::cout << "\x1b[33mForm copy assignment operator called\033[0m" << std::endl;
	new (this) Form(obj.getName(),obj.getGrade2sign(), obj.getGrade2exec(), obj._is_signed);
	return *this;
}

int		Form::setGrade2exec(int gradeExec){
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

int		Form::setGrade2sing(int gradeSign){
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

std::string Form::getName(void)const{
	return _name;
}

bool Form::isSigned(void)const{
	return _is_signed;
}

int Form::getGrade2sign(void)const{
	return _grade2sign;
}

int Form::getGrade2exec(void)const{
	return _grade2exec;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, Form const &obj){
	return out << "The form's name: " << obj.getName() << "\nsigned :" << obj.isSigned() << "\ngrade to sign: " << obj.getGrade2sign() << "\ngrade to execute: " << obj.getGrade2exec() << std::endl;
}

void Form::beSigned(Bureaucrat &obj){
	if (obj.getGrade() <= _grade2sign)
		_is_signed = true;
	else
		throw(GradeTooLowException());
}