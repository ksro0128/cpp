#include "RPN.hpp"

std::stack<int> RPN::_st;

void RPN::calculate(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (i % 2 == 1) // 띄어쓰기 판단
		{
			if (str[i] != ' ')
			{
				std::cout << "Invalid argument" << std::endl;
				return ;
			}
			else
				continue ;
		}
		if (isdigit(str[i])) // 숫자면 stack에 push
			_st.push(str[i] - '0');
		else
		{
			try
			{
				switch (str[i]) // 연산자면 연산 후 집어넣기
				{
					case '+':
						plus();
						break ;
					case '-':
						minus();
						break ;
					case '*':
						multiply();
						break ;
					case '/':
						divide();
						break ;
					default:
					{
						std::cout << "Invalid argument" << std::endl;
						return ;
					}
				}
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
				return ;
			}
		}
	}
	if (_st.size() != 1)
		std::cout << "Invalid argument" << std::endl;
	else
		std::cout << _st.top() << std::endl;
}

void RPN::plus()
{
	if (_st.size() < 2)
		throw std::runtime_error("Invalid argument");
	int second = _st.top();
	_st.pop();
	int first = _st.top();
	_st.pop();
	_st.push(first + second);
}

void RPN::minus()
{
	if (_st.size() < 2)
		throw std::runtime_error("Invalid argument");
	int second = _st.top();
	_st.pop();
	int first = _st.top();
	_st.pop();
	_st.push(first - second);
}

void RPN::multiply()
{
	if (_st.size() < 2)
		throw std::runtime_error("Invalid argument");
	int second = _st.top();
	_st.pop();
	int first = _st.top();
	_st.pop();
	_st.push(first * second);
}

void RPN::divide()
{
	if (_st.size() < 2)
		throw std::runtime_error("Invalid argument");
	int second = _st.top();
	if (second == 0)
		throw std::runtime_error("Division by zero attempted");
	_st.pop();
	int first = _st.top();
	_st.pop();
	_st.push(first / second);
}