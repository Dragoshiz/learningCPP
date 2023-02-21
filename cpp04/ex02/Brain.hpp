#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain{
	public:
		Brain();
		Brain(Brain const &);
		~Brain();
		Brain& operator=(Brain const &);
	protected:
		std::string ideas[100];
};
#endif

