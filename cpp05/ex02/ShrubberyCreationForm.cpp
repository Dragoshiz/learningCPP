#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("The no name ShrubberyCreationForm", 145, 137, false, "no target")
{
	std::cout << "\x1b[32mShrubberyCreationForm default constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("the no name ShrubberyCreationForm", 145, 137, false, target){
	std::cout << "\x1b[33mShrubberyCreationForm name constructor called\033[0m" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj)
: AForm(obj.getName(), obj.getGrade2sign(), obj.getGrade2exec(), obj.isSigned(), obj.getTarget())
{
	std::cout << "\x1b[33mShrubberyCreationForm copy constructor called\033[0m" << std::endl;
	this->setGrade2exec(obj.getGrade2exec());
	this->setGrade2sign(obj.getGrade2sign());
	this->setSigned(obj.isSigned());
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "\x1b[31mShrubberyCreationForm destructor called\033[0m" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj){
	std::cout << "\x1b[33mShrubberyCreationForm copy assignment operator called\033[0m" << std::endl;
	this->setGrade2exec(obj.getGrade2exec());
	this->setGrade2sign(obj.getGrade2sign());
	this->setSigned(obj.isSigned());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)const{
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream execFile(filename.c_str());
	if (execFile.is_open())
	{
		execFile << "      /\\          /\\    \n";
		execFile << "     /  \\        /  \\   \n";
		execFile << "    /    \\      /    \\  \n";
		execFile << "   /______\\    /______\\ \n";
		execFile << "      ||          ||    " << std::endl;
	}
	else
		std::cout << "FILE NOT OPEN" << std::endl;
	std::cout << filename << " executed successfully by " << executor.getName() << std::endl;
	execFile.close();
}
