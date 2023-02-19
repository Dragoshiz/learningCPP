#include "ClapTrap.hpp"

//to do getters and modify the constructor with std::string
ClapTrap::ClapTrap(): _name("Default ClapTrap"), _hitPoints(10), _energyPoints(10), _attckDmg(0){
	std::cout << this->_name << "\x1b[36m default constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string _name):
_name(_name), _hitPoints(10), _energyPoints(10), _attckDmg(0){
	std::cout << this->_name << "\x1b[36m name constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "\x1b[36ClapTrap copy constructor called\033[0m" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap(){
	std::cout << "\x1b[31mClapTrap destructor called\033[0m" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &obj){
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attckDmg = obj._attckDmg;
	std::cout << "\x1b[36m Copy assignment operator called\033[0m" << std::endl;
	return *this;
}
void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints > 0){
		std::cout << this->getName() << "\x1b[95m took: \033[0m " << amount << "\x1b[95m points of damage!!\033[0m" << std::endl;
		this->_hitPoints -= amount;
		std::cout << "\x1b[95mHitpoint left: \033[0m" << this->_hitPoints << std::endl;
	}
	else
		std::cout << this->_name << "\x1b[95m STOP is already dead!\033[0m" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << this->_name << "\x1b[95m is repairing itself...\033[0m" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "\x1b[95mHit point + \033[0m" << amount << "\x1b[95m, total HitPoint:  \033[0m" << this->_hitPoints << std::endl;
	}
	else if ( this->_energyPoints == 0)
		std::cout << this->_name << "\x1b[95m has not enough energy points!\033[0m" << std::endl;
	else
		std::cout << this->_name << "\x1b[95m is already dead!\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << this->_name << " attacks " << target << ", causing "  << getAttackDmg() << " points of damage!"<< std::endl;
		this->_energyPoints--;
	}
	else if ( this->_energyPoints == 0)
		std::cout << this->_name << "\x1b[95m has not enough energy points!\033[0m" << std::endl;
	else
		std::cout << this->_name << " \x1b[95m is already dead!\033[0m" << std::endl;
}
