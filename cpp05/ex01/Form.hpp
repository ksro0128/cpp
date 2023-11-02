#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Form
{
	public:
		Form();
		Form(const std::string name, int grade);
		~Form();
		Form(const Form& ref);
		Form&	operator=(const Form& ref);
		std::string getName() const;
		int			getGrade() const;
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

std::ostream& operator<<(std::ostream &os, const Form& obj);

#endif