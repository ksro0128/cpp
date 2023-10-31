#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap 
{
	public:
		DiamondTrap();
		DiamondTrap(std::string Name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &fragtrap);
		DiamondTrap &operator=(const DiamondTrap &fragtrap);
		void	getInfo() const;
		void	whoAmI();
	private:
		std::string	Name;
};

#endif