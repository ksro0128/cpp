#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		exit(1);
	}
	Harl Harl;
	Harl.harlFilter(argv[1]);

}