#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cstdio>
#include <limits>

class ScalarConverter{
	public:
		~ScalarConverter();
		static void convert(const char *arg);
	private:
		ScalarConverter();
};
#endif

