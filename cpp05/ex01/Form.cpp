#include "Form.hpp"

Form::Form(const Form& ref) 
: _name(ref._name), _isSigned(ref._isSigned), _gradeToSign(ref._gradeToSign), _gradeToExecute(ref._gradeToExecute) {}
Form::~Form() {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
}


Form& Form::operator=(const Form& ref)
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

std::string	Form::getName() const { return (_name); }

bool Form::getIsSigned() const { return (_isSigned); }

int	Form::getGradeTosign() const { return (_gradeToSign); }

int Form::getGradeToExecute() const { return (_gradeToExecute); }

void Form::beSigned(const Bureaucrat& a)
{
	if (_isSigned == true)
		return ;
	else if (a.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw() { return ("Grade too high"); }

const char* Form::GradeTooLowException::what() const throw() { return ("Grade too low"); }

std::ostream& operator<<(std::ostream &os, const Form& obj)
{
	os << obj.getName() << ", Form grade to sign " << obj.getGradeTosign() << ", grade to Execute " << obj.getGradeToExecute() << ", sign status ";
	if (obj.getIsSigned())
		os << "signed";
	else
		os << "unsigned";
	return (os);
}