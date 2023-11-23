#include "Form.hpp"

int main(void)
{
	try
	{
		std::cout << "test 1 : normal run" << std::endl;
		Bureaucrat a("testA", 75); 
		Form fa("formA", 75, 75);
		std::cout << a << std::endl;
		std::cout << fa << std::endl;
		a.signForm(fa);
		std::cout << fa << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "test 2 : exception(grade too low - sign)" << std::endl;
		Bureaucrat b("testB", 42);
		Form fb("formB", 32, 32);
		std::cout << b << std::endl;
		std::cout << fb << std::endl;
		b.signForm(fb);
		std::cout << fb << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "test 3 : exception(grade too high - constructor)" << std::endl;
		Form fc("formC", -1, 32);
		std::cout << fc << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "test 3 : exception(grade too low - constructor)" << std::endl;
		Form fd("formD", 155, 32);
		std::cout << fd << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}