#include "iter.hpp"

template<typename T>
void ft_print(T a)
{
	std::cout << a << ' ';
}

int main() 
{
	int a[] = {1, 2, 3, 4, 5};	 //int double string에 대한 정상 동작
	iter(a, 5, ft_print);
	std::cout << std::endl;
	double b[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(b, 5, ft_print);
	std::cout << std::endl;
	std::string c[] = {"abc", "def", "12345", "qwer", "zxcv"};
	iter(c, 5, ft_print);
	std::cout << std::endl;

	try // null pointer input
	{
		int *x;

		x = 0;
		iter(x, 3, ft_print);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
