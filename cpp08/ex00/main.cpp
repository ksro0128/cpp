#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	try
	{
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		std::vector<int>::iterator viter = easyfind(v, 3);
		for (; viter != v.end(); viter++)
			std::cout << *viter << ' ';
		std::cout << std::endl;
		std::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		std::list<int>::iterator liter = easyfind(l, 2);
		for (; liter != l.end(); liter++)
			std::cout << *liter << ' ';
		std::cout << std::endl;
		std::list<int>::iterator liter_error = easyfind(l, 7);
		for (; liter_error != l.end(); liter_error++)
			std::cout << *liter_error << ' ';
	}
	catch (std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}