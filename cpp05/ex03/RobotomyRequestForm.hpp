#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		RobotomyRequestForm&	operator=(RobotomyRequestForm ref);
		void	execute(Bureaucrat const & executor) const;
	private:
		RobotomyRequestForm();
		bool randomGenerator() const;
};

#endif