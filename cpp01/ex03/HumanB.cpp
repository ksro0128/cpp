#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(void)
{

}

void	HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->name << " doesn't have weapon" << std::endl;
	else
		std::cout << this->name << " attacks with their " \
		<< this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
