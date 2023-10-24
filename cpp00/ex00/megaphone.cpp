#include <iostream>

int	main(int argc, char **argv)
{
	int	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
					argv[i][j] -= 32;
				j++;
			}
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return (0);
}