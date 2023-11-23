#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string name, const std::string target,const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& ref);
		virtual ~AForm();
		std::string getName() const;
		std::string getTarget() const;
		bool		getIsSigned() const;
		int			getGradeTosign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat& a);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void		swap(AForm &rhs );
	protected:
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
		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		void setSign(bool sign);
	private:
		AForm();
		AForm&	operator=(const AForm& ref);
		const std::string	_name;
		const std::string	_target;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream &os, const AForm& obj);

#endif