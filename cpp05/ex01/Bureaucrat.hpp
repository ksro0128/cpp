#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade(int i);
		void		decrementGrade(int i);
		void		signForm(Form &rhs);

	private:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat&	operator=(const Bureaucrat& ref);
		const std::string	_name;
		int					_grade;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& obj);

#endif