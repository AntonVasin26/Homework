#include "geometry.hpp"


namespace Gm
{
	double vp(const Gm::Point* v1, const Gm::Point* v2)
	{
		return (v1->x * v2->y - v2->x * v1->y);
	}

	double dist(const Gm::Point& p1,const Gm::Point& p2)
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
	}

	std::ostream& operator<< (std::ostream& stream, const Close_Shape& sh)
	{
		return sh.print(stream);
	};

//SPoligon
	std::ostream& SPoligon::print(std::ostream& stream) const
	{
		 stream << "\nSimple Poligon\t count of point: " << std::size(points) << " points: ";
		for (auto point : points)
		{
			stream << *point << '\t';
		}
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double SPoligon::S() const
	{
		double S = 0;
		int len = std::size(points);
		Gm::Point V1;
		for (auto point=1; point < len; ++point)
		{
			V1 = *points[point - 1] - *points[point];
			S += vp(&V1, points[point]);
		}
		V1 = *points[0] - *points[len - 1];
		S += vp(&V1, points[0]);
		return abs(S)/2.0;
	}
	double SPoligon::P() const
	{
		double P = 0;
		int len = std::size(points);
		for (auto point = 1; point < len; ++point)
		{
			P += Gm::dist(*points[point - 1], *points[point]);
		}
		P += Gm::dist(*points[0], *points[len - 1]);
		return abs(P);
	}
//Quadrilaterals
	std::ostream& Quadrilaterals::print(std::ostream& stream) const
	{
		stream << "\nQuadrilaterals \t points: ";
		for (auto point : points)
		{
			stream << *point << '\t';
		}
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}

//Square
	std::ostream& Square::print(std::ostream& stream) const
	{
		stream << "\nSquare \t points: ";
		for (auto point : points)
		{
			stream << *point << '\t';
		}
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Square::S() const
	{
		Gm::Point V1 = *points[1] - *points[0];
		Gm::Point V2 = *points[2] - *points[1];
		return abs(vp(&V1, &V2));
	}
//rectangle
	std::ostream& Rectangle::print(std::ostream& stream) const
	{
		stream << "\nRectangle \t points: ";
		for (auto point : points)
		{
			stream << *point << '\t';
		}
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Rectangle::S() const
	{
		Gm::Point V1 = *points[1] - *points[0];
		Gm::Point V2 = *points[2] - *points[1];
		return abs(vp(&V1, &V2));
	}

//Parallelogram
	std::ostream& Parallelogram::print(std::ostream& stream) const
	{
		stream << "\nParallelogram \t points: ";
		for (auto point : points)
		{
			stream << *point << '\t';
		}
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Parallelogram::S() const
	{
		Gm::Point V1 = *points[1] - *points[0];
		Gm::Point V2 = *points[2] - *points[1];
		return abs(vp(&V1, &V2));
	}

//Rhomb
	std::ostream& Rhomb::print(std::ostream& stream) const
	{
		stream << "\nRhomb \t points: ";
		for (auto point : points)
		{
			stream << *point << '\t';
		}
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}

//Triangle
	std::ostream& Triangle::print(std::ostream& stream) const
	{
		stream << "\nTriangle \t points: ";
		for (auto point : points)
		{
			stream << *point << '\t';
		}
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Triangle::S() const
	{
		Gm::Point V1 = *points[1] - *points[0];
		Gm::Point V2 = *points[2] - *points[1];
		return abs(vp(&V1, &V2))/2.0;
	}

//Ellipse
	std::ostream& Ellipse::print(std::ostream& stream) const
	{
		stream << "\nEllipse     a = " << a << "    b = " << b;
		stream << "\n intersection with canonical axes: ";
		for (auto point : points)
		{
			stream << *point << "    ";
		}
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Ellipse::S() const
	{
		return Pi*a*b;
	}

	double Ellipse::P() const
	{
		return 4 * Pi*(a * b + a - b) / (a + b);
	}
//Circle
	std::ostream& Ñircle::print(std::ostream& stream) const
	{
		stream << "\nÑircle \tcenter " << points[0] << "\tR =" << r;
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Ñircle::S() const
	{
		return Pi * r * r;
	}

	double Ñircle::P() const
	{
		return 2 * Pi * r;
	}
}