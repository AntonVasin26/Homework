#include "geometry.hpp"


namespace Gm
{
	double vp(const Gm::Point& v1, const Gm::Point& v2)
	{
		return (v1.x * v2.y - v2.x * v1.y);
	}

	double dist(const Gm::Point& p1, const Gm::Point& p2)
	{
		Gm::Point p = p1 - p2;
		return sqrt(pow(p.x, 2) + pow(p.y, 2));
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

	std::ostream& operator << (std::ostream& os, const Point& p)
	{
		os << '(' << p.x << ',' << p.y << ')';
		return os;
	}

	std::istream& operator>>(std::istream& in, Point& p)
	{
		char c;
		in >> p.x;
		in >> c;
		in >> p.y;
		return in;


	void SPoligon::print() const
	{
		std::cout << "\nSimple Poligon\t points:";
		for (auto point : points)
		{
			std::cout << point;
		}
	}

	double SPoligon::S() const
	{
		double S = 0;
		int len = std::size(points);
		for (auto point=1; point < len; ++point)
		{
			S += vp(points[point-1] - points[point], points[point]);
		}
		S += vp(points[0] - points[len - 1], points[0]);
		return S;
	}
	double SPoligon::P() const
	{
		double P = 0;
		int len = std::size(points);
		for (auto point = 1; point < len; ++point)
		{
			P += Gm::dist(points[point - 1], points[point]);
		}
		P += Gm::dist(points[0], points[len - 1]);
		return P;
	}
}