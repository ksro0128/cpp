#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotomyRequestForm", target, 72, 45)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) 
: AForm(ref.getName(), ref.getTarget(), ref.getGradeTosign(), ref.getGradeToExecute())
{
	setSign(ref.getIsSigned());
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
			std::cout << getTarget() << " has been robotomized successful" << std::endl;
		else
			std::cout << getTarget() << " has been robotomized failed" << std::endl;
	}
}

bool	RobotomyRequestForm::randomGenerator() const
{
	int time = static_cast<int>(std::time(0));
	return time % 2;
}
