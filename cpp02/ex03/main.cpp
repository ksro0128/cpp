#include "Point.hpp"

float getFloat(void)
{
	float	rt;

	std::cin >> rt;
	if (std::cin.fail() || std::cin.eof())
	{
		std::cout << "Error : std::cin is fail" << std::endl;
		exit(1);
	}
	char remain = std::cin.get();
	if (remain == ' ' || remain == '\t')
	{
		std::cout << "Error : Do not put white space after input" << std::endl;
		exit(1);
	}
	if (rt > 100000 || rt < -100000)
	{
		std::cout << "Error : Input range exceeded. Please enter input within the range of -100000 to 100000" << std::endl;
		exit(1);
	}
	return (rt);
}

int main(void) 
{
	float x1, y1;
	float x2, y2;
	float x3, y3;
	float pointx, pointy;

	std::cout << "input x1 : ";
	x1 = getFloat();
	std::cout << "input y1 : ";
	y1 = getFloat();

	std::cout << "input x2 : ";
	x2 = getFloat();
	std::cout << "input y2 : ";
	y2 = getFloat();

	std::cout << "input x3 : ";
	x3 = getFloat();
	std::cout << "input y3 : ";
	y3 = getFloat();

	std::cout << "input point x : ";
	pointx = getFloat();
	std::cout << "input point y : ";
	pointy = getFloat();

	Point a(x1, y1);
	Point b(x2, y2);
	Point c(x3, y3);
	Point point(pointx, pointy);

	if (bsp(a, b, c, point) == true)
		std::cout << "point is inside" << std::endl;
	else
		std::cout << "point is outside" << std::endl;

}