#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
		Array() : _data(NULL), _size(0) {};
		explicit Array(unsigned int n) : _size(n)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = T();
		};
		~Array(){delete[] _data;};
		Array(const Array& rhs) : _size(rhs._size)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = rhs._data[i];
		};
		Array &operator=(const Array& rhs)
		{
			if (this == &rhs)
				return *this;
			delete[] _data;
			_data = new T [_size];
			for (unsigned int i = 0; i < rhs._size; i++)
				_data[i] = rhs._data[i];
			_size = rhs._size;
			return *this;
		};
		T &operator[](const unsigned int index)
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		};
		unsigned int getSize() {return _size;}
	private:
		T 				*_data;
		unsigned int	_size;
};

#endif