#pragma once
#include <iostream>
#include <vector>
#include <cmath>

namespace Gm
{
	class Point
	{
	public:
		Point() : x(0), y(0) {};
		Point(int X, int Y) : x(X * 1.0), y(Y * 1.0) {};
		Point(double X, double Y) : x(X), y(Y) {};
		Point& operator += (const Point& other);
		Point& operator -= (const Point& other);
		friend Point operator+ (const Point& a, const Point& b);
		friend Point operator- (const Point& a, const Point& b);
		friend std::ostream& operator << (std::ostream& os, const Point& p);
		friend std::istream& operator>>(std::istream& in, Point& p);
		double x, y;

		~Point() = default;
	};

	double vp(const Gm::Point* v1, const Gm::Point* v2);
	double dist(const Gm::Point& p1,const Gm::Point& p2);

	

	class Close_Shape
	{
	public:
		Close_Shape(const std::vector<Gm::Point*>& vec) : points(vec) {}
		friend std::ostream& operator<< (std::ostream& stream, const Close_Shape& sh);
		virtual std::ostream& print(std::ostream& stream) const = 0;
		virtual double S() const = 0;
		virtual double P() const = 0;
		virtual ~Close_Shape() = default;

	protected:
		std::vector<Gm::Point*> points;
		static inline const double Pi = 3.14159265358979323846;
	};

	class SPoligon : public Close_Shape
	{
	public:
		SPoligon(const std::vector<Gm::Point*>& vec) :Close_Shape(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
		virtual double P() const override;
	};

	class Quadrilaterals : public SPoligon
	{
	public:
		Quadrilaterals(const std::vector<Gm::Point*>& vec) :SPoligon(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
	};

	class Square : public Quadrilaterals
	{
	public:
		Square(const std::vector<Gm::Point*>& vec) :Quadrilaterals(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
	};

	class Rectangle : public Quadrilaterals
	{
	public:
		Rectangle(const std::vector<Gm::Point*>& vec) :Quadrilaterals(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
	};

	class Parallelogram : public Quadrilaterals
	{
	public:
		Parallelogram(const std::vector<Gm::Point*>& vec) :Quadrilaterals(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
	};

	class Rhomb : public Parallelogram
	{
	public:
		Rhomb(const std::vector<Gm::Point*>& vec) :Parallelogram(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
	};

	class Triangle : public SPoligon
	{
	public:
		Triangle(const std::vector<Gm::Point*>& vec) :SPoligon(vec) {}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
	};

	class Ellipse : public Close_Shape
	{
	public:
		Ellipse(const std::vector<Gm::Point*>& vec) :Close_Shape(vec)
		{ 
			Gm::Point p1 = *points[0];
			Gm::Point p2 = *points[2];
			a = dist(p1, p2)/2.0;
			p1 = *points[1];
			p2 = *points[3];
			b = dist(p1, p2)/2.0;
			if (b>a)
			{
				std::swap(a, b); 
			} 
		}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
		virtual double P() const override;
		double a;
		double b;
	};

	class Ñircle : public Close_Shape
	{
	public:
		Ñircle(const std::vector<Gm::Point*>& vec) :Close_Shape(vec)
		{
			Gm::Point p1 = *points[0];
			Gm::Point p2 = *points[1];
			r = dist(p1, p2);
		}
		virtual std::ostream& print(std::ostream& stream) const override;
		virtual double S() const override;
		virtual double P() const override;
		double r;

	};


}