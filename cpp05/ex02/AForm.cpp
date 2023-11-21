#include "AForm.hpp"

AForm::AForm() : _name("no name"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{

}

AForm::~AForm()
{

}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm& ref) : _name(ref._name), _isSigned(ref._isSigned), _gradeToSign(ref._gradeToSign), _gradeToExecute(ref._gradeToExecute)
{

}

AForm& AForm::operator=(const AForm& ref)
{
	if (this != &ref)
	{
		const_cast<std::string&>(_name) = ref._name;
		const_cast<int&>(_gradeToSign) = ref._gradeToSign;
		const_cast<int&>(_gradeToExecute) = ref._gradeToExecute;
		_isSigned = ref._isSigned;
	}
	return (*this);
}

std::string	AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeTosign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& a)
{
	if (a.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
		std::cout << a.getName() << " signed " << _name << std::endl;
	}
	else
	{
		std::cout << a.getName() << " couldn't sign " << _name << \
		" because this form's grade to sign is higher than the bureaucrat's grade" << std::endl;
		throw (GradeTooLowException());
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("[AForm] Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("[AForm] Grade too low");
}

std::ostream& operator<<(std::ostream &os, const AForm& obj)
{
	os << obj.getName() << ", AForm grade to sign " << obj.getGradeTosign() << ", grade to Execute " << obj.getGradeToExecute() << ", sign status ";
	if (obj.getIsSigned())
		os << "signed";
	else
		os << "unsigned";
	return (os);
}