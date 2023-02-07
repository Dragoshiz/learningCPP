#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void){}

const std::string&	Weapon::getType(void)
{
	std::string& weaponTypeRef = this->type;
	return (weaponTypeRef);
}