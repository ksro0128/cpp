#include "Array.hpp"

int main()
{
	try
	{
		Array<int> x(5); // 기본적인 테스트

		std::cout << "x : ";
		for(unsigned int i = 0; i < x.getSize(); i++)
			std::cout << x[i] << ' ';
		std::cout << std::endl;
		for(unsigned int i = 0; i < x.getSize(); i++) // 값 대입 잘 되는지 확인
			x[i] = i;
		std::cout << "x : ";
		for(unsigned int i = 0; i < x.getSize(); i++)
			std::cout << x[i] << ' ';
		std::cout << std::endl;

		Array<int> y(x); // 복사 생성자 확인
		std::cout << "y : ";
		for(unsigned int i = 0; i < y.getSize(); i++)
			std::cout << y[i] << ' ';
		std::cout << std::endl;
		Array<int> z(10);
		z = x; // 대입 연산자 확인
		std::cout << "z : ";
		for(unsigned int i = 0; i < z.getSize(); i++)
			std::cout << z[i] << ' ';
		std::cout << std::endl;
		z[5] = 123; // 에러 확인 out of bound
	}
	catch (std::exception &e)
	{
		std::cout << std::endl << "Exception : " << e.what() << std::endl;
	}
}