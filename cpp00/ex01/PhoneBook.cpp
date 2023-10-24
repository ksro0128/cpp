#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->idx = 0;
}
void	PhoneBook::add_contact(void)
{
	std::string	str;

	str = ft_getline("first name     : ");
	contacts[idx % 8].set_first_name(str);
	str = ft_getline("last name      : ");
	contacts[idx % 8].set_last_name(str);
	str = ft_getline("nickname       : ");
	contacts[idx % 8].set_nickname(str);
	while (1)
	{
		int flag = 0;
		str = ft_getline("phone number   : ");
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				std::cout << "PLEASE INPUT ONLY NUMBER" << std::endl;
				flag = 1;
				break ;
			}
		}
		if (flag == 0)
		{
			contacts[idx % 8].set_phone_number(str);
			break ;
		}
	}
	str = ft_getline("darkest secret : ");
	contacts[idx % 8].set_darkest_secret(str);
	idx += 1;
	if (idx == 16)
		idx = 8;
}

void	PhoneBook::search_contact(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phonenumber;
	int			end;

	if (this->idx == 0)
	{
		std::cout << "EMPTY! PLEASE ADD CONTACT!!\n";
		return ;
	}
	std::cout << "     index|first name| last name|  nickname\n";
	if (this->idx < 8)
		end = this->idx;
	else
		end = 8;
	for (int i = 0; i < end; i++)
	{
		first_name = this->contacts[i].get_first_name();
		last_name = this->contacts[i].get_last_name();
		nickname = this->contacts[i].get_nickname();
		std::cout << itos(i) << '|' << modify_string(first_name) << '|';
		std::cout << modify_string(last_name) << '|' << modify_string(nickname) << '\n';
	}
	finding_printing();
}

std::string	PhoneBook::itos(int num)
{
	std::string	rt;

	rt = "         ";
	rt.push_back(num + '0');
	return (rt);
}

std::string	PhoneBook::modify_string(std::string str)
{
	if (str.size() < 10)
	{
		while (str.size() < 10)
		{
			str.insert(0, " ");
		}
		return (str);
	}
	else
	{
		std::string	rt;
		rt = str.substr(0, 9);
		rt.push_back('.');
		return (rt);
	}
}

void	PhoneBook::finding_printing(void)
{
	std::string idx;

	while (1)
	{
		std::cout << "index : ";
		std::getline(std::cin, idx);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << "THIS IS AN ABNORMAL INPUT" << std::endl;
			exit(1);
		}
		int index = idx[0] - '0';
		if (idx.size() != 1)
			std::cout << "PLEASE ENTER THE CORRECT INDEX (0 ~ 7)" << std::endl;
		else if (index >= 0 && index <= 7 && index >= this->idx)
		{
			std::cout << "THIS INDEX IS EMPTY" << std::endl;
		}
		else if (index >= 0 && index <= 7 && index < this->idx)
		{
			contacts[index].print_infomation();
			return ;
		}
		else
			std::cout << "PLEASE ENTER THE CORRECT INDEX (0 ~ 7)" << std::endl;
	}
}

std::string	PhoneBook::ft_getline(std::string front)
{
	std::string	str;

	while (1)
	{
		std::cout << front;
		std::getline(std::cin, str);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << "THIS IS AN ABNORMAL INPUT" << std::endl;
			exit(1);
		}
		if (str.size() == 0)
			continue;
		return (str);
	}
}