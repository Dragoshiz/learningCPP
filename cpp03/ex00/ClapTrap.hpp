#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap{
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(ClapTrap const &);
		~ClapTrap();
		void attack(const std::string &);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);
		ClapTrap& operator=(ClapTrap const &);
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attckDmg;
};

#endif