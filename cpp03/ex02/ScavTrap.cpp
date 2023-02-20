#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name)
{
	this->setName(_name);
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttckDmg(20);
	std::cout << _name << "\x1b[32m ScavTrap constructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(){
	this->setName("Default ScarvTrap");
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttckDmg(20);
	std::cout << this->getName() << "\x1b[32m ScavTrap default constructor called\033[0m" << std::endl;
}

ScavTrap::~ScavTrap(void){
	std::cout << this->getName() << "\x1b[31m ScavTrap distructor called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj): ClapTrap(){
	std::cout << this->getName() << "\x1b[32m ScavTrap copy constructor called\033[0m" << std::endl;
	*this = obj;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &obj){
	this->setName(obj.getName()); 
	this->setAttckDmg(obj.getAttackDmg());
	this->setEnergyPoint(obj.getEnergyPoints());
	this->setHitPoint(obj.getHitPoints());
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}

void ScavTrap::guardGate(void){
	if (this->getEnergyPoints() > 0  && this->getHitPoints() > 0)
		std::cout << this->getName() << "\x1b[32m is in Gate keeper mode!\033[0m" << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << this->getName() << "\x1b[32m is too tired\033[0m" << std::endl;
	else
		std::cout << this->getName() << "\x1b[32m is dead\033[0m" << std::endl;
}
