#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
	ScavTrap scav;
	ScavTrap scav2("Trapper");
	ScavTrap scav3(scav);
	ScavTrap scav4 = scav;

	std::cout << "Hi my name is " << scav.getName() << " and I have " << scav.getAttackDmg() << " and " << scav.getHitPoints() <<  std::endl;
	std::cout << "Hi my name is " << scav2.getName() << " and I have " << scav2.getAttackDmg() << " and " << scav2.getHitPoints() <<  std::endl;

	scav.attack(scav2.getName());
	scav2.takeDamage(scav.getAttackDmg());

	scav.attack(scav2.getName());
	scav2.takeDamage(scav.getAttackDmg());

	scav.attack(scav2.getName());
	scav2.takeDamage(scav.getAttackDmg());

	scav2.beRepaired(20);

	scav.attack(scav2.getName());
	scav2.takeDamage(scav.getAttackDmg());

	scav.attack(scav2.getName());
	scav2.takeDamage(scav.getAttackDmg());

	scav.attack(scav2.getName());
	scav2.takeDamage(scav.getAttackDmg());

	scav2.beRepaired(20);

	scav2.guardGate();
	return 0;
}