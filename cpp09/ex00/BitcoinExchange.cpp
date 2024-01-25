#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_data;

void BitcoinExchange::getData()
{
	std::ifstream data("data.csv");
	if (!data) 																			// data.csv가 없을 때
		throw std::runtime_error("data.csv Not Found");
	std::string line;
	std::getline(data, line);
	if ("date,exchange_rate" != line) 													// 헤더가 올바르지 않을 때
		throw std::runtime_error("Invalid data header");
	while (std::getline(data, line))
	{
		if (line.length() == 0) 														// 빈 줄이 있을 때
			throw std::runtime_error("Invalid data format : Encountered an empty line");
		std::istringstream iss(line);
		std::string date;
		std::string exchange_rate_s;
		float exchange_rate;
		std::getline(iss, date, ',');
		if (checkDate(date) == false) 													// date가 올바르지 않을 때
			throw std::runtime_error("Invalid data format : Date " + date);
		std::getline(iss, exchange_rate_s, ',');
		exchange_rate = getExchangeRate(exchange_rate_s);
		if (exchange_rate < 0) 															// exchange_rate이 올바르지 않을 때
			throw std::runtime_error("Invalid data format : Exchange_rate " + exchange_rate_s);
		if (!iss.eof()) 																// date,exchange_rate 형식이 지켜지지 않았을 때
			throw std::runtime_error("Invalid data format : " + line);
		if (_data.find(date) != _data.end()) 											// 겹친 date가 들어왔을 때
			throw std::runtime_error("Invalid data format : Duplicate dates " + date);
		_data[date] = exchange_rate;
		std::map<std::string, float>::iterator iter = _data.end();
		iter--;
		if (date != iter->first) 														// date의 순서가 올바르지 않을 때
			throw std::runtime_error("Invalid data format : The date " + date + " is out of order");
	}
	if (_data.begin()->first == "")
		throw std::runtime_error("Invalid data format : Empty data");
}

void BitcoinExchange::PrintBitcoinPriceByDate(std::string inputfile)
{
	std::ifstream input(inputfile);
	if (!input) 																		// inputfile을 열 수 없을 때
		throw std::runtime_error("Could not open " + inputfile);
	if (inputfile.length() < 5 || inputfile.substr(inputfile.length() - 4) != ".txt")	// inputfile name 형식이 아닐 때
		throw std::runtime_error("Invalid inputfile name : " + inputfile);
	std::string line;
	std::getline(input, line);
	if (line != "date | value") 														// header가 잘 못 되었을 때
		throw std::runtime_error("Invalid inputfile header");
	while (std::getline(input, line))
	{
		if (line.length() == 0) 														// 빈 줄이 있을 때
			continue ;
		std::istringstream iss(line);
		std::string date;
		std::string pipe;
		std::string coin_s;
		float coin;
		std::getline(iss, date, ' ');
		if (checkDate(date) == false) 													// date 형식이 잘 못 되었을 때
		{
			std::cout << "Error : Invalid inputfile format : Date " << date << std::endl;
			continue ;
		}
		std::getline(iss, pipe, ' ');
		if (pipe != "|") 																// date | value 형식이 지켜지지 않았을 때
		{
			std::cout << "Error : Invalid inputfile format : " << line << std::endl;
			continue ;
		}
		std::getline(iss, coin_s, ' ');
		coin = getExchangeRate(coin_s);
		if (coin < 0 || coin > 1000) 													// value가 잘 못 되었을 때
		{
			std::cout << "Error : Invalid inputfile format : Value " << coin_s << std::endl;
			continue ;
		}
		if (!iss.eof()) 																// date | value 형식이 지켜지지 않았을 때
		{
			std::cout << "Error : Invalid inputfile format : " << line << std::endl;
			continue ;
		}
		std::map<std::string, float>::iterator iter = _data.lower_bound(date);
		if (iter == _data.begin())
		{
			if (date < _data.begin()->first)											// date 가 data의 가장 빠른 날짜보다 빠를 때
				std::cout << "Error : The input date " << date << " is earlier than the earliest date in the database" << std::endl;
			else
				std::cout << date << " => " << coin << " = " << iter->second * coin << std::endl;
		}
		else if (iter->first == date)
			std::cout << date << " => " << coin << " = " << iter->second * coin << std::endl;
		else
		{
			iter--;
			std::cout << date << " => " << coin << " = " << iter->second * coin << std::endl;
		}
	}

}


bool BitcoinExchange::checkDate(std::string date)
{
	if (date.length() != 10) // yyyy-mm-dd
		return false;
	std::istringstream iss(date);
	std::string token;
	std::getline(iss, token, '-');
	int year = getYear(token);
	std::getline(iss, token, '-');
	int month = getMonth(token);
	std::getline(iss, token, '-');
	int day = getDay(year, month, token);

	if (year == -1 || month == -1 || day == -1)
		return false;
	else
		return true;
}

double	BitcoinExchange::getExchangeRate(std::string str)
{
	if (str.length() == 0)
		return -1;
	for (int i = 0; str[i]; i++)
	{
		if (isdigit(str[i]) == 0 && str[i] != '.')
			return -1;
	}
	char *check;
	double ret = strtod(str.c_str(), &check);

	if (check[0] != '\0')
		return -1;
	if (ret > 2147483647.0)
		return -1;
	return static_cast<float>(ret);
}


int BitcoinExchange::getFebruaryLastday(int year)
{
	if (year % 4 != 0)
		return 28;
	else if (year % 100 != 0)
		return 29;
	else if (year % 400 != 0)
		return 28;
	else
		return 29;
}

int BitcoinExchange::getYear(std::string year)
{
	if (year.length() != 4)
		return -1;
	for (int i = 0; i < 4; i++)
	{
		if (isdigit(year[i]) == false)
			return -1;
	}
	int ret = atoi(year.c_str());
	return ret;
}

int BitcoinExchange::getMonth(std::string month)
{
	if (month.length() != 2)
		return -1;
	for (int i = 0; i < 2; i++)
	{
		if (isdigit(month[i]) == false)
			return -1;
	}
	int ret = atoi(month.c_str());
	if (ret > 12 || ret < 1)
		return -1;
	return ret;
}

int BitcoinExchange::getDay(int year, int month, std::string day)
{
	if (year == -1 || month == -1)
		return -1;
	if (day.length() != 2)
		return -1;
	for (int i = 0; i < 2; i++)
	{
		if (isdigit(day[i]) == false)
			return -1;
	}
	int ret = atoi(day.c_str());
	if (ret > 31 || ret < 1)
		return -1;
	int lastday_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2)
		lastday_month[1] = getFebruaryLastday(year);
	if (ret > lastday_month[month - 1])
		return -1;
	return ret;
}