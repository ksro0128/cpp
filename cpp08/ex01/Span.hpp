#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <exception>

class Span
{
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span& rhs);
		Span &operator=(const Span& rhs);
		void addNumber(const int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		template<typename T>
		void addNumbers(T begin, T end)
		{
			for (T it = begin; it != end; it++)
				addNumber(*it);
		}

	private:
		Span();
		std::map<int, bool> _m;
		size_t				_maxSize;
		unsigned int		_shortest;
};

#endif