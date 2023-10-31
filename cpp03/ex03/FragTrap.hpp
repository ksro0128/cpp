#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string Name);
		virtual ~FragTrap();
		FragTrap(const FragTrap &scavtrap);
		FragTrap &operator=(const FragTrap &scavtrap);
		virtual void	getInfo() const;
		void	highFivesGuys();
};

#endif