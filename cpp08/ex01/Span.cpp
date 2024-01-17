#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::~Span() { }

Span::Span(const Span& rhs) : _maxSize(rhs._maxSize)
{
	int vsize = rhs._v.size();
	for (int i = 0; i < vsize; i++)
	{
		_v.push_back(rhs._v[i]);
	}
}

Span &Span::operator=(Span rhs)
{
	std::swap(_v, rhs._v);
	std::swap(_maxSize, rhs._maxSize);
	return (*this);
}

void Span::addNumber(int num)
{
	int vsize = _v.size();
	if (vsize >= _maxSize)
		throw std::out_of_range("Index out of bounds");
	_v.push_back(num);
}

unsigned int Span::shortestSpan()
{
	int vsize = _v.size();
	if (vsize <= 1)
		throw std::invalid_argument("it must have at least 2 elements");
	sort(_v.begin(), _v.end());
	unsigned int ret = 4294967295;
	for (int i = 0; i < vsize - 1; i++)
	{
		unsigned int tmp = _v[i + 1] - _v[i];
		if (tmp < ret)
			ret = _v[i + 1] - _v[i];
	}
	return ret;
}

unsigned int Span::longestSpan() {return _v[_v.size() - 1] - _v[0];}