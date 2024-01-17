#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	if (str.length() == 0)
	{
		std::cout << "Don't input NULL" << std::endl;
		return ;
	}
	int	type = getType(str);
	switch (type)
	{
		case M_CHAR :
			caseChar(str);
			break ;
		case M_INT :
			caseInt(str);
			break ;
		case M_FLOAT :
			caseFloat(str);
			break ;
		case M_DOUBLE :
			caseDouble(str);
			break ;
		default :
			std::cout << "error" << std::endl;
	}
}

int ScalarConverter::getType(std::string str)
{
	if (str.length() == 1 && isdigit(str[0]) == 0)
		return (M_CHAR);
	else if (isInt(str) == 1)
		return (M_INT);
	else if (isInt(str) == -1)
		return (M_OVERFLOW);
	else
		return (isFloatDouble(str));
}

int ScalarConverter::isInt(std::string str)
{
	size_t	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	long long	x;
	std::istringstream iss(str);
	iss >> x;
	if (x < -2147483648 || x > 2147483647)
		return (-1);
	return (1);
}

int	ScalarConverter::isFloatDouble(std::string str)
{
	size_t	i = 0;
	bool	flag = false;
	if (str == ".f")
		return (M_ERROR);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < str.length() - 1)
	{
		if (str[i] == '.')
		{
			if (flag == true)
				return (M_ERROR);
			flag = true;
			i++;
			continue ;
		}
		if (isdigit(str[i]) == 0)
			return (M_ERROR);
		i++;
	}
	if (flag == false && str[i] == '.')
		return (M_DOUBLE);
	if (flag == false)
		return (M_ERROR);
	if (str[i] == 'F' || str[i] == 'f')
		return (M_FLOAT);
	if (isdigit(str[i]))
		return (M_DOUBLE);
	return (M_ERROR);
}

void	ScalarConverter::caseChar(std::string str)
{
	char	x;

	std::istringstream iss(str);
	iss >> x;
	std::cout << "char: " << x << std::endl;
	std::cout << "int: " << static_cast<int>(x) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(x) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(x) << std::endl;
}

void	ScalarConverter::caseInt(std::string str)
{
	int	x;

	std::istringstream iss(str);
	iss >> x;
	if ((x >= 0 && x < 32) || x == 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else if (x < 0 || x > 127)
		std::cout << "char: " << "Impossible" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(x) << "'" << std::endl;
	std::cout << "int: " << x << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(x) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(x) << std::endl;
}

void	ScalarConverter::caseFloat(std::string str)
{
	float	x;
	int		p;
	size_t	sign = 0;
	
	if (str[0] == '+' || str[0] == '-')
		sign = 1;
	if (str.length() > 8 + sign)
	{
		std::cout << "Float precision exceeded" << std::endl;
		return ;
	}
	str.resize(str.length() - 1);
	std::istringstream iss(str);
	iss >> x;
	p = getDecimalPrecision(str);
	if (p == 0)
	{
		if ((x >= 0 && x < 32) || x == 127)
			std::cout << "char: " << "Non displayable" << std::endl;
		else if (x < 0 || x > 127)
			std::cout << "char: " << "Impossible" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(x) << "'" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	if (p == 0)
		std::cout << "int: " << static_cast<int>(x) << std::endl;
	else
		std::cout << "int: Impossible" << std::endl;
	if (p == 0)
	{
		std::cout << std::fixed << std::setprecision(1) << "float: " << x << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(x) << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(p) << "float: " << x << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(x) << std::endl;
	}
}

void	ScalarConverter::caseDouble(std::string str)
{
	double	x;
	int		p;
	size_t	sign = 0;
	
	if (str[0] == '+' || str[0] == '-')
		sign = 1;
	if (str.length() > 16 + sign)
	{
		std::cout << "Double precision exceeded" << std::endl;
		return ;
	}
	std::istringstream iss(str);
	iss >> x;
	p = getDecimalPrecision(str);
	if (p == 0)
	{
		if ((x >= 0 && x < 32) || x == 127)
			std::cout << "char: " << "Non displayable" << std::endl;
		else if (x < 0 || x > 127)
			std::cout << "char: " << "Impossible" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(x) << "'" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;
	if (x < -2147483648.0 || x > 2147483647.0)
		std::cout << "int: Impossible" << std::endl;
	else if (p == 0)
		std::cout << "int: " << static_cast<int>(x) << std::endl;
	else
		std::cout << "int: Impossible" << std::endl;
	if (p == 0)
	{
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(x) << "f" << std::endl;
		std::cout << "double: " << x << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(p) << "float: " << static_cast<float>(x) << "f" << std::endl;
		std::cout << "double: " << x << std::endl;
	}
}

int	ScalarConverter::getDecimalPrecision(std::string str)
{
	size_t	i = 0;
	int		ret = 0;
	int		zeroCnt = 0;

	i = str.find('.', 0);
	i++;
	while (str[i])
	{
		if (str[i] == '0')
			zeroCnt++;
		i++;
		ret++;
	}
	if (str[i - 1] == 'f' || str[i - 1] == 'F')
		ret--;
	if (ret == zeroCnt)
		ret = 0;
	return (ret);
}
