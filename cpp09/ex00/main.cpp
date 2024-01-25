#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage : " << argv[0] << " <inputFilename.txt>" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange::getData();
		BitcoinExchange::PrintBitcoinPriceByDate(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}