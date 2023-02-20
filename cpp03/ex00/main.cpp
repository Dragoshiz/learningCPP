#include "ClapTrap.hpp"

int main(void){
	ClapTrap clap;
	ClapTrap trap1("Clapper");
	ClapTrap trap2(trap1);
	ClapTrap trap3 = clap;

	std::cout << "Hi my name is " << clap.getName() << std::endl;
	for(int i= 0; i < 12; i++)
	{
		clap.attack(trap2.getName());
	}
	return 0;
}
