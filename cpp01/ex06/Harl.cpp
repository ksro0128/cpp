#include "Harl.hpp"

Harl::Harl(void)
{
	complains[0] = "DEBUG";
	complains[1] = "INFO";
	complains[2] = "WARNING";
	complains[3] = "ERROR";
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
}

int	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == complains[i])
		{
			return (i);
		}
	}
	return (-1);
}

void	Harl::harlFilter(std::string level)
{
	switch (complain(level))
	{
		case 0:
			(this->*f[0])();
		case 1:
			(this->*f[1])();
		case 2:
			(this->*f[2])();
		case 3:
			(this->*f[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}


void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}