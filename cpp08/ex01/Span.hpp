#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
		size_t _size;
		std::vector<int> d_vectr;
};
#endif

