#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "\x1b[36mDefault FragTrap constructor\033[0m" << std::endl;
	this->setName("Default FragTrap");
	this->setAttckDmg(30);
	this->setEnergyPoint(100);
	this->setHitPoint(100);
}

FragTrap::~FragTrap(){
	std::cout << "\x1b[31mFragTrap destructor\033[0m" << std::endl;
}


FragTrap::FragTrap(std::string _name)
{
	this->setName(_name);
	this->setAttckDmg(30);
	this->setEnergyPoint(100);
	this->setHitPoint(100);
	std::cout <<_name <<"\x1b[36m FragTrap constructor\033[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj): ClapTrap(){
	std::cout << "\x1b[36mCopy FragTrap constructor\033[0m" << std::endl;
	*this = obj;
}

FragTrap & FragTrap::operator=(FragTrap const &obj){
	std::cout << "\x1b[36mFragTrap copy assignment operator\033[0m" << std::endl;
	this->setName(obj.getName());
	this->setAttckDmg(obj.getHitPoints());
	this->setEnergyPoint(obj.getEnergyPoints());
	this->setHitPoint(obj.getHitPoints());
	return *this;
}

void FragTrap ::highFivesGuys(){
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
		std::cout <<"\x1b[36m"+this->getName()+ "\033[0m"  << "\x1b[36m gives everyone a high five\033[0m" << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << this->getName() << "\x1b[36m have 0 energy left\033[0m" << std::endl;
	else
		std::cout << this->getName() << "\x1b[36m is dead\033[0m" << std::endl;
}