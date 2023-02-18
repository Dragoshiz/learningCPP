#ifndef HELLO_HPP
#define HELLO_HPP
#include <iostream>

class Hello{
	public:
		Hello();
		Hello(Hello const &);
		~Hello();
		Hello& operator=(Hello const &);
	private:
};
#endif

