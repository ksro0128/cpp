#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat&	operator=(const Bureaucrat& ref);
		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade(int i);
		void		decrementGrade(int i);
		void		signForm(Form &a);
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


	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& obj);

#endif