#include "HumanB.hpp"

HumanB::~HumanB()
{
	std::cout << this->_name << " logged out" << std::endl;
}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " spawned" << std::endl;
}


void HumanB::setType(Weapon weapon)
{
	_weapon = weapon;
}


void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with " << this->_weapon.getType() << std::endl;
}