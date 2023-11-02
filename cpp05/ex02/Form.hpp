#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		~Form();
		Form(const Form& ref);
		Form&	operator=(const Form& ref);
		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeTosign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat& a);
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
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream &os, const Form& obj);

#endif