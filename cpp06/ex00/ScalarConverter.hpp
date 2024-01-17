#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <cmath>
# include <iomanip>

# define M_CHAR			1
# define M_INT			2
# define M_FLOAT		3
# define M_DOUBLE		4
# define M_OVERFLOW		5
# define M_ERROR		6

class ScalarConverter
{
	public:
		static void convert(std::string str);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		static int	getType(std::string str);
		static int	isInt(std::string str);
		static int	isFloatDouble(std::string str);
		static void	caseNull(std::string str);
		static void	caseChar(std::string str);
		static void	caseInt(std::string str);
		static void	caseFloat(std::string str);
		static void	caseDouble(std::string str);
		static int	getDecimalPrecision(std::string str);
};

#endif