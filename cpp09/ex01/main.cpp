#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : " << argv[0] << " <argument>" << std::endl;
		return 1;
	}
	RPN::calculate(argv[1]);

}