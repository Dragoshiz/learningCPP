#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():
AForm("The no name RobotomyRequestForm", 72, 45, false, "no target")
{
	std::cout << "\x1b[32mRobotomyRequestForm default constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("The no name RobotomyRequestForm", 72, 45, false, target)
{
	std::cout << "\x1b[32mRobotomyRequestForm name constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj):
AForm(obj.getName(), obj.getGrade2sign(), obj.getGrade2exec(), obj.isSigned(), obj.getTarget())
{
	std::cout << "\x1b[33mRobotomyRequestForm copy constructor called\033[0m" << std::endl;
	this->setGrade2exec(obj.getGrade2exec());
	this->setGrade2sign(obj.getGrade2sign());
	this->setSigned(obj.isSigned());
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "\x1b[31mRobotomyRequestForm destructor called\033[0m" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &obj){
	std::cout << "\x1b[33mRobotomyRequestForm copy assignment operator called\033[0m" << std::endl;
	this->setGrade2exec(obj.getGrade2exec());
	this->setGrade2sign(obj.getGrade2sign());
	this->setSigned(obj.isSigned());
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const{
	std::cout << "* Makes some drilling noise * \n";
	srand(time(NULL));
	int randomNum = rand() % 2;
	if(randomNum == 1){
		std::cout << getName() << "has been robotomized successfully by " << executor.getName() << std::endl;
	}
	else
		std::cout << "The robotomy has failed!" << std::endl;
}
