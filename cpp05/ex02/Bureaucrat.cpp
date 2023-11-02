#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("no name"), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw (GradeTooHighException());
	else if (_grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref._name), _grade(ref._grade)
{
	
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& ref)
{
	if (this != &ref)
	{
		const_cast<std::string&>(_name) = ref._name;
		_grade = ref._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(int i)
{
	if (_grade - i < 1)
		throw (GradeTooHighException());
	else
		_grade -= i;
}

void Bureaucrat::decrementGrade(int i)
{
	if (_grade + i > 150)
		throw (GradeTooLowException());
	else
		_grade += i;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Bureaucrat] Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Bureaucrat] Grade too low");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade : " << obj.getGrade() << ".";
	return os;
}