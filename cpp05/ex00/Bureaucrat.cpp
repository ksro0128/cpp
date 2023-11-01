#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{

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

int Bureaucrat::getGrade()
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw (GradeTooHighException());
	else
		_grade++;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 1)
		throw (GradeTooLowException());
	else
		_grade++;
}