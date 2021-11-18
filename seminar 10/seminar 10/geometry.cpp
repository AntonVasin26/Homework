#include "Header.hpp"


namespace Gm
{
	double vp(const Gm::Vector& v1, const Gm::Vector& v2)
	{
		return (v1.x * v2.y - v2.x * v1.y);
	}

	double dist(const Gm::Vector& p1,const Gm::Vector& p2)
	{
		Gm::Vector p = p1 - p2;
		return sqrt(pow(p.x, 2) + pow(p.y, 2));
	}

	Vector& Vector::operator += (const Vector& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector& Vector::operator -= (const Vector& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector operator + (const Vector& a, const Vector& b)
	{
		Vector ans = a;
		ans += b;
		return ans;
	}

	Vector operator - (const Vector& a, const Vector& b)
	{
		Vector ans = a;
		ans -= b;
		return ans;
	}

	std::ostream& operator << (std::ostream& os, const Vector& p)
	{
		os << '(' << p.x << ',' << p.y << ')';
		return os;
	}

	std::istream& operator>>(std::istream& in, Vector& p)
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

	std::ostream& Close_Shape::print(std::ostream& stream) const
	{
		for (auto Vector : Vectors)
		{
			stream << Vector << "    ";
		}
		return stream;
	}

//SPoligon
	std::ostream& SPoligon::print(std::ostream& stream) const
	{
		stream << "\nSimple Poligon\t count of Vector: " << std::size(Vectors) << " Vectors: ";
		Close_Shape::print(stream);
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double SPoligon::S() const
	{
		double S = 0;
		int len = std::size(Vectors);
		Gm::Vector V1;
		for (auto Vector=1; Vector < len; ++Vector)
		{
			V1 = Vectors[Vector - 1] - Vectors[Vector];
			S += vp(V1, Vectors[Vector]);
		}
		V1 = Vectors[0] - Vectors[len - 1];
		S += vp(V1, Vectors[0]);
		return abs(S)/2.0;
	}
	double SPoligon::P() const
	{
		double P = 0;
		int len = std::size(Vectors);
		for (auto Vector = 1; Vector < len; ++Vector)
		{
			P += Gm::dist(Vectors[Vector - 1], Vectors[Vector]);
		}
		P += Gm::dist(Vectors[0], Vectors[len - 1]);
		return abs(P);
	}
//Quadrilaterals
	std::ostream& Quadrilaterals::print(std::ostream& stream) const
	{
		stream << "\nQuadrilaterals \t points: ";
		Close_Shape::print(stream);
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}

//Square
	std::ostream& Square::print(std::ostream& stream) const
	{
		stream << "\nSquare \t points: ";
		Close_Shape::print(stream);
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Square::S() const
	{
		Gm::Vector V1 = Vectors[1] - Vectors[0];
		Gm::Vector V2 = Vectors[2] - Vectors[1];
		return abs(vp(V1, V2));
	}
//rectangle
	std::ostream& Rectangle::print(std::ostream& stream) const
	{
		stream << "\nRectangle \t points: ";
		Close_Shape::print(stream);
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Rectangle::S() const
	{
		Gm::Vector V1 = Vectors[1] - Vectors[0];
		Gm::Vector V2 = Vectors[2] - Vectors[1];
		return abs(vp(V1, V2));
	}

//Parallelogram
	std::ostream& Parallelogram::print(std::ostream& stream) const
	{
		stream << "\nParallelogram \t points: ";
		Close_Shape::print(stream);
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Parallelogram::S() const
	{
		Gm::Vector V1 = Vectors[1] - Vectors[0];
		Gm::Vector V2 = Vectors[2] - Vectors[1];
		return abs(vp(V1, V2));
	}

//Rhomb
	std::ostream& Rhomb::print(std::ostream& stream) const
	{
		stream << "\nRhomb \t points: ";
		Close_Shape::print(stream);
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}

//Triangle
	std::ostream& Triangle::print(std::ostream& stream) const
	{
		stream << "\nTriangle \t points: ";
		Close_Shape::print(stream);
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Triangle::S() const
	{
		Gm::Vector V1 = Vectors[1] - Vectors[0];
		Gm::Vector V2 = Vectors[2] - Vectors[1];
		return abs(vp(V1, V2))/2.0;
	}

//Ellipse
	std::ostream& Ellipse::print(std::ostream& stream) const
	{
		stream << "\nEllipse     a = " << a << "    b = " << b;
		stream << "\nintersection with canonical axes: ";
		Close_Shape::print(stream);
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Ellipse::S() const
	{
		return std::numbers::pi*a*b;
	}

	double Ellipse::P() const
	{
		return 4 * std::numbers::pi*(a * b + a - b) / (a + b);
	}
//Circle
	std::ostream& Ñircle::print(std::ostream& stream) const
	{
		stream << "\nCircle \tcenter " << Vectors[0] << "\tR =" << r;
		stream << "\nSquare = " << this->S() << "\nPerimeter = " << this->P() << '\n';
		return stream;
	}
	double Ñircle::S() const
	{
		return std::numbers::pi * r * r;
	}

	double Ñircle::P() const
	{
		return 2 * std::numbers::pi * r;
	}
}