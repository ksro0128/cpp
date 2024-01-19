#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		~MutantStack() {};
		MutantStack(const MutantStack<T>& rhs) : std::stack<T>(rhs) {};
		MutantStack &operator=(const MutantStack& rhs)
		{
			if (this == &rhs)
				return *this;
			std::stack<T>::operator=(rhs);
			return *this;
		}
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};

#endif