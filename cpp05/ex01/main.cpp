#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		std::cout << "====testA====" << std::endl;
		Bureaucrat a("testA", 75); // 기본적인 테스트
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "====testB====" << std::endl;
		Bureaucrat b("testB", -1); // 생성자가 잘 못 되었을 때
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "====testC====" << std::endl;
		Bureaucrat c("testC", 3); // 승진이 잘 못 되었을 때
		std::cout << c << std::endl;
		c.incrementGrade(10);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "====testD====" << std::endl;
		Bureaucrat d("testD", 140); // 강등이 잘 못 되었을 때
		std::cout << d << std::endl;
		d.decrementGrade(12);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}