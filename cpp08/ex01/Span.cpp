#include "Span.hpp"

Span::Span(unsigned int N): _size(N), d_list(){
	std::cout << "\x1b[32mSpan default constructor called\033[0m" << std::endl;
}

Span::Span(Span const &obj){
	std::cout << "\x1b[33mSpan copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Span::~Span(){
	std::cout << "\x1b[31mSpan destructor called\033[0m" << std::endl;
}

Span& Span::operator=(Span const &obj){
	//assign obj to this variables!
	std::cout << "\x1b[33mSpan copy assignment operator called\033[0m" << std::endl;
}

void Span::addNumber(void){
	if (_is_filled != _size){

	}
}