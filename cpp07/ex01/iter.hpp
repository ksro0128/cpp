#ifndef ITER_HPP
# define ITER_HPP 

# include <iostream>

template<typename T>
void iter(T *arr, size_t length, void (* f)(T &))
{
	if (arr == NULL || f == NULL)
		throw std::logic_error("Null pointer input");
	for (size_t i = 0; i < length; i++)
	{
		f(arr[i]);
	}
}

#endif