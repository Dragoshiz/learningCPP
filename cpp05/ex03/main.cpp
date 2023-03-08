#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(){
	{
		std::cout <<"=== 1st scope ===\n" << std::endl;
		std::cout << "====== Trying no matching form type======" << std::endl;
		Intern me;
		AForm *neu;
		try{
			neu = me.makeForm("anyad", "you");
			std::cout << neu->getName() << std::endl;
		}
		catch (std::exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout <<"=== 2nd scope ===\n" << std::endl;
		std::cout << "====== Trying ShrubberyCreationForm form type======" << std::endl;
		Intern me;
		AForm *neu;
		try{
			neu = me.makeForm("ShrubberyCreationForm", "you");
			std::cout << neu->getName() << std::endl;
		}
		catch (std::exception& e){
			std::cerr << e.what() << std::endl;
		}
		delete neu;
	}
	{
		std::cout <<"=== 3rd scope ===\n" << std::endl;
		std::cout << "====== Trying RobotomyRequestForm type======" << std::endl;
		Intern me;
		AForm *neu;
		try{
			neu = me.makeForm("RobotomyRequestForm", "me");
			std::cout << neu->getName() << std::endl;
		}
		catch (std::exception& e){
			std::cerr << e.what() << std::endl;
		}
		delete neu;
	}
	{
		std::cout <<"=== 4th scope ===\n" << std::endl;
		std::cout << "====== Trying PresidentialPardonForm type======" << std::endl;
		Intern me;
		AForm *neu;
		try{
			neu = me.makeForm("PresidentialPardonForm", "she");
			std::cout << neu->getName() << std::endl;
		}
		catch (std::exception& e){
			std::cerr << e.what() << std::endl;
		}
		delete neu;
	}

	return 0;
}
