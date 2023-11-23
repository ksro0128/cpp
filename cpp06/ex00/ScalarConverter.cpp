#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
	switch (determineType(str))
	{
		case 1 :
		{
			char x = str[0];
			charDisplay(x);
			break ;
		}
		case 2 :
		{
			intDisplay(strtol(str.c_str(), NULL, 10));
			break ;
		}
		case 3 :
		{
			float x = strtof(str.c_str(), NULL);
			floatDisplay(x, hasDecimal(x));
			break ;
		}
		case 4 :
		{
			double x = strtod(str.c_str(), NULL);
			doubleDisplay(x, hasDecimal(x));
			break ;
		}
		case 5 :
		{
			float x;
			if (str == "-inff")
				x = -std::numeric_limits<float>::infinity();
			else if (str == "inff" || str == "+inff")
				x = std::numeric_limits<float>::infinity();
			else
				x = std::numeric_limits<float>::quiet_NaN();
			floatDisplay(x, 2);
			break ;
		}
		case 6 :
		{
			double x;
			if (str == "-inf")
				x = -std::numeric_limits<double>::infinity();
			else if (str == "inf" || str == "+inf")
				x = std::numeric_limits<double>::infinity();
			else
				x = std::numeric_limits<double>::quiet_NaN();
			doubleDisplay(x, 2);
			break ;
		}
		default :
			std::cout << "Bad input" << std::endl;
			break ;
	}
}

int ScalarConverter::determineType(std::string str)
{
	if (str.size() == 0)
		return 0;
	if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
		return 5;
	if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
		return 6;
	if (isDigitInString(str))
	{
		if (isInt(str))
			return 2;
		else
			return 0;
	}
	else if (str.size() == 1)
		return 1;
	else if (isFloatOrDouble(str))
	{
		if (floatOrDouble(str))
			return 3;
		else
			return 4;
	}
	else
		return 0;
}

bool ScalarConverter::isDigitInString(std::string str)
{
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == 1 && str.size() == 1)
		return false;
	while (i < str.size())
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isInt(std::string str)
{
	const char *cstr = str.c_str();
	long long x = strtoll(cstr, NULL, 10);
	if (x < -2147483648 || x > 2147483647)
		return false;
	return true;
}

bool ScalarConverter::isFloatOrDouble(std::string str)
{
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[0] == '.')
		return false;
	bool pointFlag = false;
	bool fFlag = false;
	while (i < str.size())
	{
		if (fFlag == true)
			return false;
		if (pointFlag == false && !isdigit(str[i]))
		{
			if (str[i] == '.')
				pointFlag = true;
			else
				return false;
		}
		else if (pointFlag == true && !isdigit(str[i]))
		{
			if (str[i] == 'f' || str[i] == 'F')
				fFlag = true;
			else
				return false;
		}
		i++;
	}
	return true;
}

bool ScalarConverter::floatOrDouble(std::string str)
{
	if (str[str.size() - 1] == 'f' || str[str.size() - 1] == 'F')
		return true;
	else
		return false;
}

void ScalarConverter::charDisplay(char x)
{
	std::cout << "char: '" << x << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(x) << std::endl;
	std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(x) << ".0" << std::endl;
}

void ScalarConverter::intDisplay(int x)
{
	std::cout << "char: ";
	if ((x > 0 && x < 32) || x == 127)
		std::cout << "Non displayalbe" << std::endl;
	else if (x < 0 || x > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(x) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(x) << std::endl;
	std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(x) << ".0" << std::endl;
}

void ScalarConverter::floatDisplay(float x, int flag)
{
	if (flag == 2)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(x) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(x) << std::endl;
		return ;
	}
	std::cout << "char: ";
	if ((x > 0 && x < 32) || x == 127)
		std::cout << "Non displayalbe" << std::endl;
	else if (x < 0 || x > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(x) << "' (warning: It may not be accurate.)" << std::endl;
	std::cout << "int: " << static_cast<int>(x) << " (warning: It may not be accurate.)" << std::endl;
	if (flag)
	{
		std::cout << "float: " << x << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(x) << std::endl;
	}
	else
	{
		std::cout << "float: " << x << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(x) << ".0" << std::endl;
	}
}

void ScalarConverter::doubleDisplay(double x, int flag)
{
	if (flag == 2)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(x) << "f" << std::endl;
		std::cout << "double: " << x << std::endl;
		return ;
	}
	std::cout << "char: ";
	if ((x > 0 && x < 32) || x == 127)
		std::cout << "Non displayalbe" << std::endl;
	else if (x < 0 || x > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(x) << "' (warning: It may not be accurate.)" << std::endl;
	std::cout << "int: " << static_cast<int>(x) << " (warning: It may not be accurate.)" << std::endl;
	if (flag)
	{
		std::cout << "float: " << static_cast<float>(x) << "f (warning: It may not be accurate.)" << std::endl;
		std::cout << "double: " << x << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(x) << ".0f (warning: It may not be accurate.)" << std::endl;
		std::cout << "double: " << x << ".0" << std::endl;
	}
}

bool ScalarConverter::hasDecimal(float x) 
{
    float fractionalPart = x - static_cast<int>(x);
    return fractionalPart > 0.0f;
}

bool ScalarConverter::hasDecimal(double x) 
{
    double fractionalPart = x - static_cast<int>(x);
    return fractionalPart > 0.0;
}
