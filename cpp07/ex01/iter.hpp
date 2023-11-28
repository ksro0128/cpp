#ifndef ITER_HPP
# define ITER_HPP 

# include <iostream>

template<typename Tarr, typename Tfunc>
void iter(Tarr *arr, size_t length, Tfunc a)
{
	for (size_t i = 0; i < length; i++)
		a(arr[i]);
}

#endif