#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Random robot"), _hitPoints(10), _energyPoints(10), _attckDmg(0){
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name):
_name(_name), _hitPoints(10), _energyPoints(10), _attckDmg(0){
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap(){
	std::cout << "\x1b[31mDestructor called\033[0m" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &obj){
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attckDmg = obj._attckDmg;
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return *this;
}
void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "causing " << amount << "points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints > 0 || this->_energyPoints > 0)
	{
		std::cout << this->_name << "\x1B is repairing itself...\033[0m" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " has not enough energy points!" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << this->_name << " attacks " << target << ", causing "  << getAttackDmg() << " points of damage!"<< std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " has not enough energy points!" << std::endl;
}
