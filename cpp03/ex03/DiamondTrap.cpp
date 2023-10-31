#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap created" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 30;
	this->MaxHP = 100;
}

DiamondTrap::DiamondTrap(std::string Name)
{
	this->Name = Name;
	std::cout << "DiamondTrap " << this->Name << " created" << std::endl;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	this->MaxHP = 100;
	Name.append("_clap_name");
	ClapTrap::Name = Name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->Name << " destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& fragtrap)
{
	this->Name = fragtrap.getName();
	this->HitPoints = fragtrap.getHitPoints();
	this->EnergyPoints = fragtrap.getEnergyPoints();
	this->AttackDamage = fragtrap.getAttackDamage();
	this->MaxHP = 100;
	std::cout << "DiamondTrap " << this->Name << " Copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap& fragtrap)
{
	if (this != &fragtrap)
	{
		this->Name = fragtrap.getName();
		this->HitPoints = fragtrap.getHitPoints();
		this->EnergyPoints = fragtrap.getEnergyPoints();
		this->AttackDamage = fragtrap.getAttackDamage();
		this->MaxHP = 100;
	}
	std::cout << "DiamondTrap " << this->Name << " Copy assignment operator called" << std::endl;
	return (*this);
}

void	DiamondTrap::getInfo() const
{
	std::cout << "DiamondTrap " << this->Name << " infomation. " << "[Hit points : " << this->HitPoints << "] [Energy points : " << this->EnergyPoints << "] [Attack damage : " << this->AttackDamage << "]" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap realName : " << this->Name << ", clapName : " << ClapTrap::Name << std::endl;
}