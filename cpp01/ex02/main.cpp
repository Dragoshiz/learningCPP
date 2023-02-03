#include <iostream>

int main(void)
{
	std::string hi_brain = "HI THIS IS BRAIN";
	// std::string justtotest = "hello it'sa me";
	std::string &stringREF = hi_brain;
	std::string *stringPTR = &hi_brain;

	std::cout << "Memory address of string: " << &hi_brain << std::endl;
	std::cout << "Memory address held by reference: " << &stringREF << std::endl;
	std::cout << "Memory address held by pointer : " << stringPTR  << std::endl;
	// std::cout << "Memory address of pointer: "<< &stringPTR << std::endl;

	// stringREF = justtotest;
	// stringPTR = &justtotest;
	std::cout << "Value of string: " << hi_brain << std::endl;
	std::cout << "Value of reference: " << stringREF << std::endl;
	std::cout << "Value of pointer: " << *stringPTR << std::endl;
}