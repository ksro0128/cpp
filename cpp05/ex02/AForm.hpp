#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm& ref);
		AForm&	operator=(const AForm& ref);
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


	protected:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream &os, const AForm& obj);

#endif