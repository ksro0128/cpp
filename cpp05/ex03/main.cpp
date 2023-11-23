#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern in;
		Bureaucrat person("surkim", 42);
		AForm *x = in.makeForm("shrubbery creation", "x");
		
		person.signForm(*x);
		person.executeForm(*x);
		delete x;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Intern in;
		Bureaucrat person("surkim", 42);
		AForm *x = in.makeForm("robotomy request", "y");
		
		person.signForm(*x);
		person.executeForm(*x);
		delete x;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Intern in;
		Bureaucrat person("surkim", 2);
		AForm *x = in.makeForm("presidential pardon", "z");
		
		person.signForm(*x);
		person.executeForm(*x);
		delete x;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	{
		Intern in;
		Bureaucrat person("surkim", 55);
		try
		{
			AForm *x = in.makeForm("no form", "x");
			person.signForm(*x);
			person.executeForm(*x);
			delete x;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception : " << e.what() << std::endl;
		}
	}
}