#include "Hello.hpp"

Hello::Hello(){
	std::cout << "\x1b[32mDefault constructor called\033[0m" << std::endl;
}

Hello::Hello(Hello const &obj){
	std::cout << "\x1b[33mCopy constructor called\033[0m" << std::endl;
}

Hello::~Hello(){
	std::cout << "\x1b[31mDestructor called\033[0m" << std::endl;
}

Hello& Hello::operator=(Hello const &obj){
	//assign obj to this variables!
	std::cout << "\x1b[33mCopy assignment operator called\033[0m" << std::endl;
}

