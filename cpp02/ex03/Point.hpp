#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float a, const float b);
		~Point();
		Point(const Point &point);
		Point &operator=(const Point &point);
		Fixed	getX() const;
		Fixed	getY() const;
	private:
		const Fixed x;
		const Fixed y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif