#pragma once
#include <iostream>
#include <vector>
#include <cmath>

namespace Gm
{
	double vp(Point){}

	class Point
	{
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
		Close_Shape(const std::vector<Point*>& vec): points(vec){}
		virtual double S();
	protected:
		std::vector<Point*> points;
	};



}