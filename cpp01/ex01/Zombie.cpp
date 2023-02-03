#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << ": got constructed" << std::endl;
}

Zombie::Zombie(){}
Zombie::~Zombie()
{
	std::cout << this->_name << ": got destructed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}