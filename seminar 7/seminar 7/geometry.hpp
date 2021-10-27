#pragma once
#include <iostream>
#include <vector>
#include <cmath>

namespace Gm
{
	struct Vector
	{
	public:
		Vector() : x(0), y(0) {};
		Vector(double X, double Y) : x(X), y(Y) {};
		Vector& operator += (const Vector& other);
		Vector& operator -= (const Vector& other);
		friend Vector operator+ (const Vector& a, const Vector& b);
		friend Vector operator- (const Vector& a, const Vector& b);
		friend std::ostream& operator << (std::ostream& os, const Vector& p);
		friend std::istream& operator>>(std::istream& in, Vector& p);
		double x, y;

		~Vector() = default;
	};

	double vp(const Gm::Vector& v1, const Gm::Vector& v2);
	double dist(const Gm::Vector& p1,const Gm::Vector& p2);

	

	class Close_Shape
	{
	public:
		Close_Shape(const std::vector<Vector>& vec) : Vectors(vec) {}
		friend std::ostream& operator<< (std::ostream& stream, const Close_Shape& sh);
		virtual std::ostream& print(std::ostream& stream) const = 0;
		virtual double S() const = 0;
		virtual double P() const = 0;
		virtual ~Close_Shape() = default;

	protected:
		std::vector<Vector> Vectors;
		static inline const double Pi = 3.14159265358979323846;
	};

	class SPoligon : public Close_Shape
	{
	public:
		SPoligon(const std::vector<Vector>& vec) :Close_Shape(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
		virtual double P() const final;
	};

	class Quadrilaterals : public SPoligon
	{
	public:
		Quadrilaterals(const std::vector<Vector>& vec) :SPoligon(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
	};

	class Square : public Quadrilaterals
	{
	public:
		Square(const std::vector<Vector>& vec) :Quadrilaterals(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
	};

	class Rectangle : public Quadrilaterals
	{
	public:
		Rectangle(const std::vector<Vector>& vec) :Quadrilaterals(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
	};

	class Parallelogram : public Quadrilaterals
	{
	public:
		Parallelogram(const std::vector<Vector>& vec) :Quadrilaterals(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
	};

	class Rhomb : public Parallelogram
	{
	public:
		Rhomb(const std::vector<Vector>& vec) :Parallelogram(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
	};

	class Triangle : public SPoligon
	{
	public:
		Triangle(const std::vector<Vector>& vec) :SPoligon(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
	};

	class Ellipse : public Close_Shape
	{
	public:
		Ellipse(const std::vector<Vector>& vec) :Close_Shape(vec), b(dist(Vectors[0], Vectors[2])), a(dist(Vectors[1],Vectors[3]))
		{ if (b>a) std::swap(a, b); }
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
		virtual double P() const override;
		double a;
		double b;
	};

	class Ñircle : public Close_Shape
	{
	public:
		Ñircle(const std::vector<Gm::Vector>& vec) :Close_Shape(vec), r(dist(Vectors[0], Vectors[1])) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
		virtual double P() const override;
		double r;

	};


}