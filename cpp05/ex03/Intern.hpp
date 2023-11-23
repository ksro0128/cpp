#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		AForm *makeForm(const std::string name, const std::string target) const;

	private:
		Intern(const Intern& ref);
		Intern&	operator=(const Intern& ref);
		AForm* makeShrubberyCreationForm(std::string target) const;
		AForm* makeRobotomyRequestForm(std::string target) const;
		AForm* makePresidentialPardonForm(std::string target) const;
		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif