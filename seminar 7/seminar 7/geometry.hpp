#pragma once
#include <iostream>
#include <vector>
#include <cmath>

namespace Gm
{
	double vp(const Gm::Point& v1, const Gm::Point& v2);

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
		double x, y;

		~Point() = default;
	};

	class Close_Shape
	{
	public:
		Close_Shape(const std::vector<Gm::Point*>& vec): points(vec){}
		virtual double S() const = 0;
		virtual double P() const = 0;
		virtual std::ostream& print() const = 0;
	protected:
		std::vector<Gm::Point*> points;
	};

	class Rect : public Close_Shape
	{
	public:
		Rect(const std::vector<Gm::Point*>& vec) :Close_Shape(vec){}
		virtual std::ostream& print() const override;
		virtual double S() const override;
		virtual double P() const override;

	};




}