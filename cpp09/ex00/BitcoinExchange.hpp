#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <exception>
# include <sstream>
# include <cstdlib>

class BitcoinExchange
{
	public:
		static void getData();
		static void PrintBitcoinPriceByDate(std::string inputfile);
	private:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		static std::map<std::string, float> _data;
		static bool		checkDate(std::string date);
		static int		getYear(std::string year);
		static int		getMonth(std::string month);
		static int		getDay(int year, int month, std::string day);
		static int		getFebruaryLastday(int year);
		static double	getExchangeRate(std::string str);
};


#endif