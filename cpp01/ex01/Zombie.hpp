#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	setname(std::string name);
		void	announce(void);
	private:
		std::string	name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif