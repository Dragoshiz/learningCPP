#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include <iostream>

class IMateriaSource{
	public:
		IMateriaSource();
		IMateriaSource(IMateriaSource const &);
		~IMateriaSource();
		IMateriaSource& operator=(IMateriaSource const &);
	private:
};
#endif

