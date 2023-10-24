#ifndef Contact_HPP
# define Contact_HPP

# include <string>
# include <iostream>

class Contact
{
	public:
		Contact(void);
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);
		void	set_first_name(std::string str);
		void	set_last_name(std::string str);
		void	set_nickname(std::string str);
		void	set_phone_number(std::string str);
		void	set_darkest_secret(std::string str);
		void	print_infomation(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif