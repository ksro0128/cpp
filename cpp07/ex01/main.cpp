#include "iter.hpp"

template<typename T>
void ft_print(T a)
{
	std::cout << a << ' ';
}

int main() 
{
	int a[] = {1, 2, 3, 4, 5};
	iter(a, 5, ft_print<int>);
	std::cout << std::endl;

	double b[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(b, 5, ft_print<double>);
	std::cout << std::endl;

	std::string c[] = {"abc", "def", "ghi", "jkl", "mnopqrst"};
	iter(c, 5, ft_print<std::string>);
	std::cout << std::endl;
}
