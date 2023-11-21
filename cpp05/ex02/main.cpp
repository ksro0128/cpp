#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat a("surkim", 137); // 정상 실행 Shrubbery

		AForm *form = new ShrubberyCreationForm("testA");

		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("surkim", 137); // 서명이 되어있지 않은 문서를 실행할 경우

		AForm *form = new ShrubberyCreationForm("testB");

		a.executeForm(*form);
		form->execute(a);
		delete form;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("surkim", 145); // 관료의 등급이 문서의 실행등급보다 낮을 경우

		AForm *form = new ShrubberyCreationForm("testC");

		a.signForm(*form);
		a.executeForm(*form);
		form->execute(a);
		delete form;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat a("surkim", 45); // 정상 실행 RobotomyRequestForm
		RobotomyRequestForm f("robot");
		a.signForm(f);
		a.executeForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}