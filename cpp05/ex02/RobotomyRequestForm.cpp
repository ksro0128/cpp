#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref.getName(), ref.getGradeTosign(), ref.getGradeToExecute())
{

}


RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm ref)
{
	swap(ref);
	return (*this);
}

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false)
		throw (NotSignedException());
	else if (getGradeToExecute() < executor.getGrade())
		throw (GradeTooLowException());
	else
	{
		std::cout << "drrrrrrr........" << std::endl;
		if (randomGenerator())
			std::cout << "success!!" << std::endl;
		else
			std::cout << "fail" << std::endl;
	}
}

bool	RobotomyRequestForm::randomGenerator() const
{
	int time = static_cast<int>(std::time(0));
	return time % 2;
}
