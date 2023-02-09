#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB{
	private:
		std::string _name;
		Weapon _weapon;
	public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void setType(Weapon weapon);
	std::string getType(void){return this->_weapon.getType();};
	void attack(void);
};

#endif