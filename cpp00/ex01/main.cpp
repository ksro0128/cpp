#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	std::string	str;

	while (true)
	{
		std::cout << "COMMAND : ";
		std::getline(std::cin, str);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << "THIS IS AN ABNORMAL INPUT" << std::endl;
			exit(1);
		}
		if (str == "ADD")
			PhoneBook.add_contact();
		else if (str == "SEARCH")
			PhoneBook.search_contact();
		else if (str == "EXIT")
			exit(0);
		else if (str.size() == 0)
			continue ;
		else
			std::cout << "COMMAND NOT FOUND" << std::endl;
	}
}