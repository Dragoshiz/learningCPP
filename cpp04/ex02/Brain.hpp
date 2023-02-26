#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain{
	public:
		Brain();
		Brain(Brain const &);
		virtual ~Brain();
		Brain& operator=(Brain const &);
		virtual void getIdeas(void);
		virtual void setIdeas(std::string);
	protected:
		std::string _ideas[100];
};
#endif

