#pragma once
#include "Header.hpp"
#include <algorithm>
#include <numeric>

class Fraction
{
	int numerator;
	unsigned int denominator;
	bool simply;
public:
	Fraction() : numerator(0), denominator(1), simply(true) {}
	Fraction(double x) : simply(true)
	{
		as_fraction(x, numerator, denominator, 10, 5e-4);
	}
	Fraction(int n, unsigned int m = 1, bool simply = true) : numerator(n), denominator(m), simply(simply)
	{
		if (simply)
		{
			simplify();
		}
	}

	explicit operator double()const
	{
		double x = numerator / denominator;
		return x;
	}

	void simplify()
	{
		int d = std::gcd(numerator,denominator);
		numerator /= d;
		denominator /= d;
	}
	friend Fraction operator+ (const Fraction a, const Fraction b);
	friend Fraction operator- (const Fraction a, const Fraction b);
	friend Fraction operator* (const Fraction a, const Fraction b);
	friend Fraction operator/ (const Fraction a, const Fraction b);
};

Fraction operator+(const Fraction a, const Fraction b)
{
	Fraction c;
	if (a.simply && b.simply)
	{
		c.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
		c.denominator = b.denominator * a.denominator;
		c.simplify();
	}
	else
	{
		c.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
		c.denominator = b.denominator * a.denominator;
	}
	return c;
}

Fraction operator+(const Fraction a, const Fraction b)
{
	Fraction c;
	if (a.simply && b.simply)
	{
		c.numerator = (a.numerator * b.denominator) - (a.denominator * b.numerator);
		c.denominator = b.denominator * a.denominator;
		c.simplify();
	}
	else
	{
		c.numerator = (a.numerator * b.denominator) - (a.denominator * b.numerator);
		c.denominator = b.denominator * a.denominator;
	}
	return c;
}


