#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form&	operator=(const Form& ref);
		~Form();
		Form(const Form& ref);
		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeTosign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat& a);

	private:
		Form();
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
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

std::ostream& operator<<(std::ostream &os, const Form& obj);

#endif