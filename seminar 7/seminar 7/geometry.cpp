#include "geometry.hpp"


namespace Gm
{
	double vp(const Gm::Point& v1, const Gm::Point& v2)
	{
		return (v1.x * v2.y - v2.x * v1.y);
	}

	Point& Point::operator += (const Point& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Point& Point::operator -= (const Point& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Point operator + (const Point& a, const Point& b)
	{
		Point ans = a;
		ans += b;
		return ans;
	}

	Point operator - (const Point& a, const Point& b)
	{
		Point ans = a;
		ans -= b;
		return ans;
	}

	double Close_Shape::S()
	{
		double S = 0;
		for (auto point=1; point < std::size(points); ++point)
		{
			S += vp(points[point-1], points[point]);
		}
	}
	double Close_Shape::P()
	{

	}
}