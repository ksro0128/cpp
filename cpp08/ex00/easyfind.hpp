#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
	{
		if (*iter == value)
			return iter;
	}
	throw std::invalid_argument("Value not found");
}
#endif