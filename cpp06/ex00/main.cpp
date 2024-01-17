#include "ScalarConverter.hpp"
#include <stdio.h>


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : " << argv[0] << " <number or char>" << std::endl;
		exit(1);
	}
	ScalarConverter::convert(argv[1]);
}
