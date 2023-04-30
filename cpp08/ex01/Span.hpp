#ifndef SPAN_HPP
#define SPAN_HPP
#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <exception>

class Span{
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &);
		~Span();
		Span& operator=(Span const &);

		void addNumber(int num);
		void addManyNumbers(void);

		void showelem(void);
		int shortestSpan(void);
		int longestSpan(void);
	private:
		class VectorSpaceException:public std::exception{
			public:
				const char* what() const throw();
		};
		class SpanNotPossibleException: public std::exception{
			public:
				const char* what() const throw();
		};
		size_t _is_filled;
		std::vector<int> d_vectr;
};


#endif

