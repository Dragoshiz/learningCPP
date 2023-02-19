#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	FragTrap frag;
	FragTrap frag2("Fragger");
	FragTrap frag3(frag);
	FragTrap frag4 = frag;

	frag.attack(frag.getName());
	frag2.takeDamage(frag.getAttackDmg());

	frag.attack(frag.getName());
	frag2.takeDamage(frag.getAttackDmg());

	frag.attack(frag.getName());
	frag2.takeDamage(frag.getAttackDmg());

	frag2.beRepaired(20);

	frag.attack(frag.getName());
	frag2.takeDamage(frag.getAttackDmg());

	frag.attack(frag.getName());
	frag2.takeDamage(frag.getAttackDmg());

	frag.attack(frag.getName());
	frag2.takeDamage(frag.getAttackDmg());

	frag2.beRepaired(20);

	frag.highFivesGuys();
	return 0;
}