#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap{
	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(ClapTrap const &);
		~ClapTrap();
		int getHitPoints(void)const{return this->_hitPoints;};
		int getAttackDmg(void)const{return this->_attckDmg;};
		int getEnergyPoints(void)const{return this->_energyPoints;};
		void setName(std::string _name){this->_name = _name;};
		void setHitPoint(int _hitPoints){this->_hitPoints = _hitPoints;};
		void setEnergyPoint(int _energyPoint){this->_energyPoints = _energyPoint;};
		void setAttckDmg(int _attckDmg){this->_attckDmg = _attckDmg;};
		std::string getName(void)const{return this->_name;};
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