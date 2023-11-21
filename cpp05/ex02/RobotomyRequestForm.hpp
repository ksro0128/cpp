#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string name);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		RobotomyRequestForm&	operator=(RobotomyRequestForm ref);
		void	beSigned(const Bureaucrat& a);
		void	execute(Bureaucrat const & executor) const;
	private:
		RobotomyRequestForm();
		bool randomGenerator() const;
};

#endif