#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base 
{
	public:
		A();
		~A();
		A(const A &rhs);
		A&	operator=(const A& rhs);
	private:
};

#endif