#ifndef Harl_HPP
# define Harl_HPP

# include <iostream>

class	Harl
{
	public :
		Harl(void);
		void	complain(std::string level);
	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		std::string	complains[4];
		void	(Harl::*f[4])(void);
};

#endif