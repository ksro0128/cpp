#include "Span.hpp"
#include <vector>

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(3);
		sp.addNumber(6);
		sp.addNumber(9);
		sp.addNumber(17);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::vector<int> v;
		for (int i = 0; i < 100000; i++)
		{
			v.push_back(i);
		}
		Span sp = Span(100001);
		sp.addNumbers(v.begin(), v.end());
		sp.addNumber(2147483647);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}