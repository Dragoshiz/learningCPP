#include "Zombie.hpp"

int main(void)
{
	std::string name;
	int n_zombies;

	std::cout << "Type number of zombies :";
	std::cin >> n_zombies;
	if (std::cin.fail())
	{
		std::cout << "Not a number!" << std::endl;
		std::cin.clear();
		return(1);
	}
	std::cout << "And the name of the zombies :";
	std::cin >> name;
	std::cout << "A HORDE OF ZOMBIES APPEARED!" << std::endl;
	Zombie *zombies = zombieHorde(n_zombies, name);

	for (int i=0; i < n_zombies; i++)
		zombies[i].announce();
	delete []zombies;
	return (0);
}