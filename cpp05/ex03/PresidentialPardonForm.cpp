#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
: AForm("PresidentialPardonForm", target, 25, 5)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) 
: AForm(ref.getName(), ref.getTarget(), ref.getGradeTosign(), ref.getGradeToExecute())
{
	setSign(ref.getIsSigned());
}


PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& ref)
{
	if (this != &ref)
		copy(ref);
	return (*this);
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getIsSigned() == false)
		throw (NotSignedException());
	else if (getGradeToExecute() < executor.getGrade())
		throw (GradeTooLowException());
	else
	{
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}
