#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n), _shortest(4294967295) {}

Span::~Span() { }

Span::Span(const Span& rhs) : _maxSize(rhs._maxSize), _shortest(rhs._shortest)
{
	_m = rhs._m;
}

Span &Span::operator=(const Span& rhs)
{
	if (this == &rhs)
		return *this;
	_m = rhs._m;
	_maxSize = rhs._maxSize;
	_shortest = rhs._shortest;
	return *this;
}

void Span::addNumber(const int num)
{
	if (_m.size() >= _maxSize)
		throw std::runtime_error("Span capacity exceeded");
	else if (_m[num] == true)
		throw std::runtime_error("Duplicate number addition attempt");
	_m[num] = true;
	std::map<int, bool>::iterator iter = _m.find(num);
	std::map<int, bool>::iterator last = _m.end();
	last--;
	if (_m.size() > 1)
	{
		unsigned int x;
		if (iter == _m.begin())
		{
			iter++;
			x = iter->first - num;
		}
		else if (iter == last)
		{
			iter--;
			x = num - iter->first;
		}
		else
		{
			iter++;
			x = iter->first - num;
			iter--;
			iter--;
			unsigned int y = num - iter->first;
			x = std::min(x, y);
		}
		_shortest = std::min(x, _shortest);
	}
}

unsigned int Span::shortestSpan()
{
	if (_m.size() < 2)
		throw std::runtime_error("Can not get shortestSpan");
	return _shortest;
}

unsigned int Span::longestSpan() 
{
	if (_m.size() < 2)
		throw std::runtime_error("Can not get longestSpan");
	std::map<int, bool>::iterator iter = _m.end();
	iter--;
	unsigned int ret = iter->first - _m.begin()->first;
	return  ret;
}
