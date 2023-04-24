#include "Span.hpp"

Span::Span(unsigned int N): _is_filled(0), d_vectr(N){
	std::cout << "\x1b[32mSpan default constructor called\033[0m" << std::endl;
}

Span::Span(Span const &obj){
	std::cout << "\x1b[33mSpan copy constructor called\033[0m" << std::endl;
	_is_filled = obj._is_filled;
	d_vectr = obj.d_vectr;
}

Span::~Span(){
	std::cout << "\x1b[31mSpan destructor called\033[0m" << std::endl;
}

Span& Span::operator=(Span const &obj){
	std::cout << "\x1b[33mSpan copy assignment operator called\033[0m" << std::endl;
	_is_filled = obj._is_filled;
	d_vectr = obj.d_vectr;
	return *this;
}

void Span::addNumber(int num){
	if (_is_filled != d_vectr.size() && num > INT_MIN && num < INT_MAX){
		std::vector<int>::iterator it = d_vectr.begin() + _is_filled;
		d_vectr.insert(it, num);
		_is_filled++;
	}
	else
		std::cout << "Array already full of elements or int overflow" << std::endl;
}

int Span::shortestSpan(void){
	int min1, min2, diff;
	if(d_vectr.size() <= 1){
		std::cout << "More elements are needed in the d_vector array." << std::endl;
		return 0;
	}
	min1 = d_vectr[0];
	min2 = d_vectr[1];
	if (min1 > min2){
		min1 = d_vectr[1];
		min2 = d_vectr[0];
	}
	diff = min2 - min1;
	for(size_t i = 2; i < _is_filled; i++){
		if(d_vectr[i] > d_vectr[i + 1]){
			if(diff > d_vectr[i] - d_vectr[i + 1])
				diff = d_vectr[i] - d_vectr[i + 1];
		}
		else
			if(diff > d_vectr[i + 1] - d_vectr[i])
				diff = d_vectr[i + 1] - d_vectr[i];
		};
	return diff;
}

int Span::longestSpan(void){
	int min, max;
	if(d_vectr.size() <= 1){
		std::cout << "More elements are needed in the d_vector array." << std::endl;
		return 0;
	}
	min = d_vectr[0];
	max = d_vectr[1];
	if (min > max){
		min = d_vectr[1];
		max = d_vectr[0];
	}
	for(size_t i = 2; i < _is_filled; i++){
		if (min > d_vectr[i])
			min = d_vectr[i];
		if (max < d_vectr[i])
			max = d_vectr[i];
	}
	return max - min;
}

void Span::addManyNumbers(void){
	srand(time(NULL));
	for (std::vector<int>::iterator it = d_vectr.begin(); it != d_vectr.end(); ++it){
		it = d_vectr.insert(it,rand() % 101);
		std::cout << *it<< "\n";
		++it;
		
	}
}

void Span::showelem(void){
}