#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
		Array() : _data(new T[0]), _size(0) {};
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
		Array &operator=(Array rhs)
		{
			std::swap(_size, rhs._size);
			std::swap(_data, rhs._data);
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