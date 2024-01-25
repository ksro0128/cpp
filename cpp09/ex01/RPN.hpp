#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <exception>


class RPN
{
	public:
		static void calculate(std::string str);
	private:
		RPN();
		~RPN();
		RPN(const RPN& rhs);
		RPN &operator=(const RPN& rhs);
		static std::stack<int> _st;
		static void plus();
		static void minus();
		static void multiply();
		static void divide();

};

#endif