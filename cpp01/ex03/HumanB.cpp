#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " spawned" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " logged out" << std::endl;
}

void HumanB::setWeapon(Weapon weapon):
	_weapon(weapon)
{
	return (this->_weapon)
}
void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with " << this->_weapon << std::endl;
}