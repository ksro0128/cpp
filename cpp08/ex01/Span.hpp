#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>

class Span
{
	public:
		explicit Span(unsigned int n);
		~Span();
		Span(const Span& rhs);
		Span &operator=(Span rhs);
		void addNumber(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
	private:
		Span();
		std::vector<int> _v;
		int _maxSize;
};

#endif