#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) 
: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw (GradeTooHighException());
	else if (_grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const { return (_grade); }

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

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade too high"); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade too low"); }

std::ostream& operator<<(std::ostream &os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade : " << obj.getGrade() << ".";
	return os;
}
