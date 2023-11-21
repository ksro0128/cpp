#include "AForm.hpp"

AForm::AForm(const AForm& ref) 
: _name(ref._name), _isSigned(ref._isSigned), _gradeToSign(ref._gradeToSign), _gradeToExecute(ref._gradeToExecute) {}
AForm::~AForm() {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
}

std::string	AForm::getName() const { return (_name); }

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

void AForm::swap(AForm &rhs)
{
	std::swap(const_cast<std::string&>(_name), const_cast<std::string&>(rhs._name));
	std::swap(const_cast<int&>(_gradeToSign), const_cast<int&>(rhs._gradeToSign));
	std::swap(const_cast<int&>(_gradeToExecute), const_cast<int&>(rhs._gradeToExecute));
	std::swap(_isSigned, rhs._isSigned);
}

void AForm::setSign(bool sign)
{
	_isSigned = sign;
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