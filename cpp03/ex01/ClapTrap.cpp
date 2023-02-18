#include "ClapTrap.hpp"

//to do getters and modify the constructor with std::string
ClapTrap::ClapTrap(): _name("Random robot"), _hitPoints(10), _energyPoints(10), _attckDmg(0){
	std::cout << this->_name << " Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name):
_name(_name), _hitPoints(10), _energyPoints(10), _attckDmg(0){
	std::cout << this->_name << " Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap(){
	std::cout << "\x1b[36mDestructor called\033[0m" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &obj){
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attckDmg = obj._attckDmg;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}
void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints > 0){
		std::cout << this->getName() << " took " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
		std::cout << "Hit points left: " << this->_hitPoints << std::endl;
	}
	else
		std::cout << this->_name << " stop! He's already dead!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << this->_name << " is repairing itself..." << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "Hit point + " << amount << ", total HitPoint: " << this->_hitPoints << std::endl;
	}
	else if ( this->_energyPoints == 0)
		std::cout << this->_name << " has not enough energy points!" << std::endl;
	else
		std::cout << this->_name << " is already dead!" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "  << getAttackDmg() << " points of damage!"<< std::endl;
		this->_energyPoints--;
	}
	else if ( this->_energyPoints == 0)
		std::cout << this->_name << " has not enough energy points!" << std::endl;
	else
		std::cout << this->_name << " is already dead!" << std::endl;
}
