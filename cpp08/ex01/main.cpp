#include "Span.hpp"
#include <ctime>

std::vector<int> generateRandomNumbers(int size)
{
	std::srand(std::time(0));
	std::vector<int> ret;

	for (int i = 0; i < size; i++)
	{
		int rNumber = std::rand() % 2147483647;
		ret.push_back(rNumber);
	}
	return ret;
}


int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(100000);
	

}