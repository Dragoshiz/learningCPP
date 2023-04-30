#include "Span.hpp"

Span::Span():_is_filled(0), d_vectr(0){
	std::cout << "Default constructor called span of size 5" << std::endl;

}

Span::Span(unsigned int N):_is_filled(0), d_vectr(N){
	std::cout << "\x1b[32mSpan default constructor called\033[0m" << std::endl;
}

Span::Span(Span const &obj): d_vectr(obj.d_vectr.size()){
	std::cout << "\x1b[33mSpan copy constructor called\033[0m" << std::endl;
	_is_filled = obj._is_filled;
	std::copy(obj.d_vectr.begin(), obj.d_vectr.end(), d_vectr.begin());
}

Span::~Span(){
	std::cout << "\x1b[31mSpan destructor called\033[0m" << std::endl;
}

Span& Span::operator=(Span const &obj){
	std::cout << "\x1b[33mSpan copy assignment operator called\033[0m" << std::endl;
	_is_filled = obj._is_filled;
	size_t sizes = std::min(d_vectr.size(), obj.d_vectr.size()); 
	std::copy(obj.d_vectr.begin(), obj.d_vectr.begin() + sizes, d_vectr.begin());
	return *this;
}

void Span::addNumber(int num){
	if (_is_filled != d_vectr.size() && num > std::numeric_limits<int>::min() && num <  std::numeric_limits<int>::max()){
		d_vectr[_is_filled] = num;
		_is_filled++;
	}
	else
		std::cout << "Array already full of elements or int overflow" << std::endl;
}

int Span::shortestSpan(void){
	try{
		if (_is_filled <= 1)
			throw(SpanNotPossibleException());
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
		exit(1);
	}
	int diff = std::numeric_limits<int>::max();
	int res = 0;
	std::sort(d_vectr.begin(), d_vectr.end());
	std::cout << "elems sorted :\n";
	showelem(); 
	for (size_t i=0; i < d_vectr.size() - 1; i++){
		res = d_vectr[i + 1] - d_vectr[i];
		if (res < diff)
			diff = res;
	}
	return  diff;
}

int Span::longestSpan(void){
	try{
		if (_is_filled <= 1)
			throw(SpanNotPossibleException());
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
		exit(1);
	}
	std::sort(d_vectr.begin(), d_vectr.end());
	int long_span = d_vectr[d_vectr.size() - 1] - d_vectr[0];
	return long_span;
}

void Span::addManyNumbers(void){
	try{
		if(_is_filled >= d_vectr.size())
			throw(VectorSpaceException());
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
		exit(1);
	}
	srand(time(NULL));
	for (size_t i=_is_filled; i < d_vectr.size(); i++){
		d_vectr[i] = rand() % 101;
		_is_filled++;
	}
}

void Span::showelem(void){
	for (size_t i=0; i < d_vectr.size(); i++){
		std::cout << d_vectr[i] << "\n";
	}
}

const char* Span::VectorSpaceException::what() const throw(){
	return "Cannot add more elements, vector has not enough space";
}

const char* Span::SpanNotPossibleException::what() const throw(){
	return "More elements needed, cannot calculate span";
}