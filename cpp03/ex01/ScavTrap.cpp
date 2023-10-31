#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap created" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	this->MaxHP = 100;
}

ScavTrap::ScavTrap(std::string Name)
{
	this->Name = Name;
	std::cout << "ScavTrap " << this->Name << " created" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	this->MaxHP = 100;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->Name << " destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
{
	this->Name = scavtrap.getName();
	this->HitPoints = scavtrap.getHitPoints();
	this->EnergyPoints = scavtrap.getEnergyPoints();
	this->AttackDamage = scavtrap.getAttackDamage();
	this->MaxHP = 100;
	std::cout << "ScavTrap " << this->Name << " Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap& scavtrap)
{
	if (this != &scavtrap)
	{
		this->Name = scavtrap.getName();
		this->HitPoints = scavtrap.getHitPoints();
		this->EnergyPoints = scavtrap.getEnergyPoints();
		this->AttackDamage = scavtrap.getAttackDamage();
		this->MaxHP = 100;
	}
	std::cout << "ScavTrap " << this->Name << " Copy assignment operator called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->HitPoints == 0)
		std::cout << "ScavTrap " << this->Name << " is dead. Can not attack" << std::endl;
	else if (this->EnergyPoints > 0)
	{
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << this->Name << " doesn't have Energy points" << std::endl;
}

void	ScavTrap::getInfo() const
{
	std::cout << "ScavTrap " << this->Name << " infomation. " << "[Hit points : " << this->HitPoints << "] [Energy points : " << this->EnergyPoints << "] [Attack damage : " << this->AttackDamage << "]" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->HitPoints == 0)
		std::cout << "ScavTrap " << this->Name << " is dead. Can not guardGate" << std::endl;
	else if (this->EnergyPoints == 0)
		std::cout << "ScavTrap " << this->Name << " doesn't have Energy points" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->Name << " is now in Gatekeeper mode" << std::endl;
		this->EnergyPoints -= 1;
	}
}