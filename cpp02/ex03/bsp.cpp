#include "Point.hpp"

float ccw(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return (x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	case1 = ccw(a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), point.getX().toFloat(), point.getY().toFloat());
	float	case2 = ccw(b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat(), point.getX().toFloat(), point.getY().toFloat());
	float	case3 = ccw(c.getX().toFloat(), c.getY().toFloat(), a.getX().toFloat(), a.getY().toFloat(), point.getX().toFloat(), point.getY().toFloat());

	if (case1 > 0 && case2 > 0 && case3 > 0)
		return (true);
	else if (case1 < 0 && case2 < 0 && case3 < 0)
		return (true);
	else
		return (false);
}
