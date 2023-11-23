#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		std::cout << "test 1 : normal run (ShrubberyCreationForm)" << std::endl;
		Bureaucrat person("surkim", 137);
		ShrubberyCreationForm form("SCF");
		
		person.signForm(form);
		person.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "test 2 : normal run (RobotomyRequestForm)" << std::endl;
		Bureaucrat person("surkim", 42);
		RobotomyRequestForm form("RRF");
		
		person.signForm(form);
		person.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "test 3 : normal run (PresidentialPardonForm)" << std::endl;
		Bureaucrat person("surkim", 4);
		PresidentialPardonForm form("PPF");
		
		person.signForm(form);
		person.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "test 4 : exception(grade too low - sign)" << std::endl;
		Bureaucrat person("surkim", 100);
		PresidentialPardonForm form("PPF");
		
		person.signForm(form);
		person.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "test 5 : exception(grade too low - execute)" << std::endl;
		Bureaucrat person("surkim", 6);
		PresidentialPardonForm form("PPF");
		
		person.signForm(form);
		person.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "test 6 : exception(is not signed)" << std::endl;
		Bureaucrat person("surkim", 6);
		PresidentialPardonForm form("PPF");
		
		person.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}