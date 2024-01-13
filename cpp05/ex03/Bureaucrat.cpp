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

void		Bureaucrat::signForm(AForm &rhs)
{
	if (rhs.getIsSigned() == true)
		std::cout << _name << " couldn't sign " << rhs.getName() << " because it has already been signed" << std::endl;
	else if (rhs.getGradeTosign() < _grade)
		std::cout << _name << " couldn't sign " << rhs.getName() << " because form's grade to sign is higher than " << _name << "'s grade" << std::endl;
	else
		std::cout << _name << " signed " << rhs.getName() << std::endl;
	rhs.beSigned(*this);
}

void		Bureaucrat::executeForm(AForm const &form)
{
	if (form.getIsSigned() == false)
		std::cout << _name << " couldn't execute " << form.getName() << " because form is not signed" << std::endl;
	else if (form.getGradeToExecute() < _grade)
		std::cout << _name << " couldn't execute " << form.getName() << " because form's grade to execute is higher than " << _name << "'s grade" << std::endl;
	else
		std::cout << _name << " executed " << form.getName() << std::endl;
	form.execute(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade too high"); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade too low"); }

std::ostream& operator<<(std::ostream &os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade : " << obj.getGrade() << ".";
	return os;
}
