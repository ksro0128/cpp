#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	MutantStack<int> m;

	for (int i = 0; i < 5; i++)
		m.push(i);
	for (MutantStack<int>::iterator iter = m.begin(); iter != m.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	std::list<int> l;
	for (int i = 0; i < 5; i++)
		l.push_back(i);
	for (std::list<int>::iterator iter = l.begin(); iter != l.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	std::vector<int> v;
	for (int i = 0; i < 5; i++)
		v.push_back(i);
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

}