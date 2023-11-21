#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <exception>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);
		void		beSigned(const Bureaucrat& a);
};

#endif