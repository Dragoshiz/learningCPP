#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon{
	private:
		std::string type;
	public:
		void setType(std::string type){this->type = type;};
		const std::string getType(void){return this->type;};
};


#endif