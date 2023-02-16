#include "ClapTrap.hpp"

//to do getters and modify the constructor with std::string
ClapTrap::ClapTrap(){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name){
	this->_name = _name;
}

ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &obj){
	std::cout << "Copy assignment operator called" << std::endl;

}
void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "causing " << amount << "points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitPoints > 0 || this->_energyPoints > 0)
	{
		std::cout << this->_name << "\x1B is repairing itself...\033" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " has not enough energy points!" << std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (this->_hitPoints > 0 || this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << "\x1B attacks \033" << target << ", causing "  << this->attckDmg << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << this->_name << " has not enough energy points!" << std::endl;
}
