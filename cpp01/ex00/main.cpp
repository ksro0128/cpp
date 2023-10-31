#include "Zombie.hpp"

int main(void)
{
	Zombie	a("a");
	Zombie	*b;

	b = newZombie("b");

	a.announce();
	b->announce();
	randomChump("c");

	delete b;

	return (0);
}