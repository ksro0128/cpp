#include "Form.hpp"

int main(void)
{
	try
	{
		std::cout << "====testA====" << std::endl; // 기본적인 테스트
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
		std::cout << "====testB====" << std::endl; // 서류의 등급이 관료의 등급보다 높은 경우
		Bureaucrat b("testB", 42);
		Form fb("formB", 32, 32);
		std::cout << b << std::endl;
		std::cout << fb << std::endl;
		b.signForm(fb); // couldn't sign 문구 출력
		fb.beSigned(b); // exception 내뱉음
		std::cout << fb << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		std::cout << "====testC====" << std::endl; // 생성자 오류 : 등급이 너무 높은 경우
		Form fc("formC", -1, 32);
		std::cout << fc << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		std::cout << "====testD====" << std::endl; // 생성자 오류 : 등급이 너무 낮은 경우
		Form fd("formD", 155, 32);
		std::cout << fd << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}