#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie is created" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << ": is created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << ": is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setname(std::string name)
{
	this->name = name;
	std::cout << "set name of zombie : " << name << std::endl;
}
