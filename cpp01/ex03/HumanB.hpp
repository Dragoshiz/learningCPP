#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB{
	private:
		std::string _name;
		std::string _weapon;
	public:
	HumanB(std::string name);
	~HumanB();
	void setWeapon(Weapon weapon){this->_weapon = weapon;};
	std::string getWeapon(void){return this->_weapon;};
	void attack(void);
};

#endif