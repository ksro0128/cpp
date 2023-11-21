#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();
		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade(int i);
		void		decrementGrade(int i);

	private:
		Bureaucrat();
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