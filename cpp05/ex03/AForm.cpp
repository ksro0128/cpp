#include "AForm.hpp"

AForm::AForm(const AForm& ref) 
: _name(ref._name), _target(ref._target), _isSigned(ref._isSigned), _gradeToSign(ref._gradeToSign), _gradeToExecute(ref._gradeToExecute) 
{}

AForm::~AForm() {}

AForm::AForm(const std::string name, const std::string target, const int gradeToSign, const int gradeToExecute) 
: _name(name), _target(target), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
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

std::string	AForm::getName() const { return (_name); }

std::string AForm::getTarget() const { return (_target);}

bool AForm::getIsSigned() const { return (_isSigned); }

int	AForm::getGradeTosign() const { return (_gradeToSign); }

int AForm::getGradeToExecute() const { return (_gradeToExecute); }

void AForm::beSigned(const Bureaucrat& a)
{
	if (_isSigned == true)
		return ;
	else if (a.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

void AForm::setSign(bool sign)
{
	_isSigned = sign;
}

void AForm::copy(AForm &ref)
{
	const_cast<std::string&>(_name) = ref._name;
	const_cast<std::string&>(_target) = ref._target;
	const_cast<int&>(_gradeToSign) = ref._gradeToSign;
	const_cast<int&>(_gradeToExecute) = ref._gradeToExecute;
	_isSigned = ref._isSigned;
}

const char* AForm::GradeTooHighException::what() const throw() { return ("Grade too high"); }

const char* AForm::GradeTooLowException::what() const throw() { return ("Grade too low"); }

const char* AForm::NotSignedException::what() const throw() { return ("It is not signed"); }

std::ostream& operator<<(std::ostream &os, const AForm& obj)
{
	os << obj.getName() << ", Form grade to sign " << obj.getGradeTosign() << ", grade to Execute " << obj.getGradeToExecute() << ", sign status ";
	if (obj.getIsSigned())
		os << "signed";
	else
		os << "unsigned";
	return (os);
}