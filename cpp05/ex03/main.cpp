#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main(){
	std::cout <<"=== 1st scope ===" << std::endl;/home/ubuntu/42/cpp/cpp05/ex02
	std::cout << "====== Trying ShrubberyCreationForm with sign grade but not execute======" << std::endl;
	{
		std::cout << "======  with sign grade but not execute======" << std::endl;
		Bureaucrat bureau("Basic bureau",140);
		AForm *forming = new ShrubberyCreationForm("Alien");
		forming->beSigned(bureau);
		bureau.executeForm(*forming);

		std::cout << "====== first it executes the one before then with no try to execute the other form======" << std::endl;
		Bureaucrat bureauB_high("Basic-high bureau",130);
		AForm *forming2 = new ShrubberyCreationForm("Another Alien");
		bureauB_high.executeForm(*forming);
		bureauB_high.executeForm(*forming2);
		delete forming;
		delete forming2;
	}
	{
		std::cout <<"\n\n=== 2nd scope ===" << std::endl;
		std::cout << "======  with sign grade but not execute======" << std::endl;
		Bureaucrat bureau("Mid bureau",50);
		AForm *roboting = new RobotomyRequestForm("Martian");
		roboting->beSigned(bureau);
		bureau.executeForm(*roboting);


		std::cout << "====== first it executes the one before then with no try to execute the other form======" << std::endl;
		Bureaucrat bureauB_high("Basic-high bureau",30);
		AForm *roboting2 = new RobotomyRequestForm("Another Martian");
		bureauB_high.executeForm(*roboting);
		bureauB_high.executeForm(*roboting2);
		delete roboting;
		delete roboting2;
	}
	{
		std::cout <<"\n\n=== 3rd scope ===" << std::endl;
		std::cout << "======  with sign grade but not execute======" << std::endl;
		Bureaucrat bureau("High class bureau",10);
		AForm *president = new PresidentialPardonForm("Uranusian");
		president->beSigned(bureau);
		bureau.executeForm(*president);


		std::cout << "====== first it executes the one before then with no try to execute the other form======" << std::endl;
		Bureaucrat bureauB_high("Highest class bureau",1);
		AForm *president2 = new PresidentialPardonForm("Another Uranusian");
		bureauB_high.executeForm(*president);
		bureauB_high.executeForm(*president2);
		delete president;
		delete president2;
	}

	return 0;
}
