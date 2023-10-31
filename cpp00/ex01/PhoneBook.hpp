#ifndef PhoneBook_HPP
# define PhoneBook_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		void		add_contact(void);
		void		search_contact(void);
	private:
		Contact		contacts[8];
		int			idx;
		std::string	modify_string(std::string str);
		std::string	itos(int num);
		std::string ft_getline(std::string front);
		void		finding_printing(void);
};

#endif