#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zmbie = new Zombie[N];
	for (int i=0; i < N; i++)
	{
		zmbie[i] = Zombie(name);
	}
	return zmbie;
}