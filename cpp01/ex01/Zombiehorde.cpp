#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	if (N <= 0)
	{
		std::cout << "error" << std::endl;
		exit(1);
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setname(name);
	}
	return (horde);
}
