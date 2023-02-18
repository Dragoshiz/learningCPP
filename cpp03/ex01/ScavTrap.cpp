#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name)
{
	this->setName(_name);
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttckDmg(20);
	std::cout << _name << "\x1b[36m Name child constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(){
	this->setName("Default ScarvTrap");
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttckDmg(20);
	std::cout << this->getName() << "\x1b[36m Default child constructor called\033[0m" << std::endl;
}

ScavTrap::~ScavTrap(void){
	std::cout << this->getName() << "\x1b[31m Child distructor called\033[0m" << std::endl;
}

void ScavTrap::guardGate(void){
	std::cout << this->getName() << "\x1b[36m is in Gate keeper mode!\033[0m" << std::endl;
}