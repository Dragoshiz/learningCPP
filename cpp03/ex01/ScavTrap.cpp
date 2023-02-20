#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name)
{
	this->setName(_name);
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttckDmg(20);
	std::cout << "ScavTrap name child constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj): ClapTrap(){
	std::cout << this->getName() << "ScavTrap copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap::ScavTrap(){
	this->setName("Default ScarvTrap");
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttckDmg(20);
	std::cout << this->getName() << "Default child constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void){
	std::cout << this->getName() << "\x1b[31m Child distructor called\033[0m" << std::endl;
}

void ScavTrap::guardGate(void){
	if (this->getEnergyPoints() > 0  && this->getHitPoints() > 0)
		std::cout << this->getName() << " is in Gate keeper mode!" << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << this->getName() << " is too tired" << std::endl;
	else
		std::cout << this->getName() << " is dead" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &obj){
	this->setName(obj.getName());
	this->setAttckDmg(obj.getAttackDmg());
	this->setEnergyPoint(obj.getEnergyPoints());
	this->setHitPoint(obj.getEnergyPoints());
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}
