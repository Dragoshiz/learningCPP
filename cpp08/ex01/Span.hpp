#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <list>
#include <algorithm>

class Span{
	public:
		Span(unsigned int N);
		Span(Span const &);
		~Span();
		Span& operator=(Span const &);

		void addNumber(void);
	private:
		size_t _size;
		size_t _is_filled;
		std::list<int> d_list;
};
#endif

