#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap created" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	this->MaxHP = 100;
}

FragTrap::FragTrap(std::string Name)
{
	this->Name = Name;
	std::cout << "FragTrap " << this->Name << " created" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	this->MaxHP = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->Name << " destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap)
{
	this->Name = fragtrap.getName();
	this->HitPoints = fragtrap.getHitPoints();
	this->EnergyPoints = fragtrap.getEnergyPoints();
	this->AttackDamage = fragtrap.getAttackDamage();
	this->MaxHP = 100;
	std::cout << "FragTrap " << this->Name << " Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap& fragtrap)
{
	if (this != &fragtrap)
	{
		this->Name = fragtrap.getName();
		this->HitPoints = fragtrap.getHitPoints();
		this->EnergyPoints = fragtrap.getEnergyPoints();
		this->AttackDamage = fragtrap.getAttackDamage();
		this->MaxHP = 100;
	}
	std::cout << "FragTrap " << this->Name << " Copy assignment operator called" << std::endl;
	return (*this);
}

void	FragTrap::getInfo() const
{
	std::cout << "FragTrap " << this->Name << " infomation. " << "[Hit points : " << this->HitPoints << "] [Energy points : " << this->EnergyPoints << "] [Attack damage : " << this->AttackDamage << "]" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (this->HitPoints == 0)
		std::cout << "FragTrap " << this->Name << " is dead. Can not highFivesGuys" << std::endl;
	else if (this->EnergyPoints == 0)
		std::cout << "FragTrap " << this->Name << " doesn't have Energy points" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->Name << " claps his hands" << std::endl;
		this->EnergyPoints -= 1;
	}
}