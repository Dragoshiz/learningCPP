#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):
	_name(name),
	_weapon(weapon)
{
	std::cout << this->_name << " appeared" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << "logged out" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}