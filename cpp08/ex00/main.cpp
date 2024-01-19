#include "easyfind.hpp"
#include <iostream>
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
		std::vector<int>::iterator iter = easyfind(v, 3);
		std::cout << "return == " << *iter << std::endl; // 리턴 확인
		
		for (; iter != v.end(); iter++) // 제일 먼저 찾은 것이 나온건지 확인
			std::cout << *iter << ' ';
		std::cout << std::endl;

		std::vector<int>::iterator iterError = easyfind(v, 42); // 없는 거 확인 error
		std::cout << *iterError << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}