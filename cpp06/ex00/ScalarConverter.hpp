#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <cmath>

class ScalarConverter
{
	public:
		static void convert(std::string str);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter&	operator=(const ScalarConverter& rhs);
		static int determineType(std::string str);
		static bool isDigitInString(std::string str);
		static bool isInt(std::string str);
		static bool isFloatOrDouble(std::string str);
		static bool floatOrDouble(std::string str);
		static void charDisplay(char x);
		static void intDisplay(int x);
		static void floatDisplay(float x, int flag);
		static void doubleDisplay(double x, int flag);
		static bool hasDecimal(float x);
		static bool hasDecimal(double x);

};

#endif