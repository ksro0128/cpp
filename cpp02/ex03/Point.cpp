#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(const float a, const float b) : x(a), y(b)
{

}

Point::~Point()
{

}

Point::Point(const Point &point) :x(point.getX()), y(point.getY())
{

}

Point	&Point::operator=(const Point &point)
{
	if (this == &point)
		return (*this);
	this->~Point();
	new(this) Point(point.getX().toFloat(), point.getY().toFloat());
	return (*this);
}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}