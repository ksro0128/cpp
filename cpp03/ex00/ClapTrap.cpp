#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap created" << std::endl;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string Name)
{
	this->Name = Name;
	std::cout << "ClapTrap " << this->Name << " created" << std::endl;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->Name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	this->Name = claptrap.getName();
	this->HitPoints = claptrap.getHitPoints();
	this->EnergyPoints = claptrap.getEnergyPoints();
	this->AttackDamage = claptrap.getAttackDamage();
	std::cout << "ClapTrap " << this->Name << " Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& claptrap)
{
	if (this != &claptrap)
	{
		this->Name = claptrap.getName();
		this->HitPoints = claptrap.getHitPoints();
		this->EnergyPoints = claptrap.getEnergyPoints();
		this->AttackDamage = claptrap.getAttackDamage();
	}
	std::cout << "ClapTrap " << this->Name << " Copy assignment operator called" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " is dead. Can not attack" << std::endl;
		return ;
	}
	if (this->EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
		this->EnergyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << this->Name << " doesn't have Energy points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " is dead. Can not take damage" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " was attacked with " << amount << " damage!" << std::endl;
	if (this->HitPoints > amount)
		this->HitPoints -= amount;
	else
	{
		this->HitPoints = 0;
		std::cout << "ClapTrap " << this->Name << " is dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " is dead. Can not be repaired" << std::endl;
		return ;
	}
	else if (this->EnergyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " doesn't have Energy points" << std::endl;
		return ;
	}
	else if (this->HitPoints == 10)
	{
		std::cout << "ClapTrap " << this->Name << " is already max HP" << std::endl;
	}
	else
	{
		unsigned int p = this->HitPoints + amount > 10 ? 10 - this->HitPoints : amount;
		std::cout << "ClapTrap " << this->Name << " has been repaired by " << p << "!" << std::endl;
		this->EnergyPoints -= 1;
		this->HitPoints += p;
	}
}

std::string	ClapTrap::getName() const
{
	return (this->Name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (this->HitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (this->EnergyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->AttackDamage);
}

void	ClapTrap::getInfo() const
{
	std::cout << "ClapTrap " << this->Name << " infomation. " << "[Hit points : " << this->HitPoints << "] [Energy points : " << this->EnergyPoints << "] [Attack damage : " << this->AttackDamage << "]" << std::endl;
}