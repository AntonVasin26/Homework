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

	Fraction(int n) : numerator(n), denominator(1U) {}

	Fraction(double x) : simply(true) {as_fraction(x, numerator, denominator, 10, 5e-4);}

	Fraction(int n, unsigned int m = 1, bool simply = true) : numerator(n), denominator(m), simply(simply) {if (simply) simplify();}

	Fraction(const Fraction& f) = default;

	Fraction(Fraction&& f) = default;

	explicit operator double()const {return static_cast<double>(numerator) / static_cast<double>(denominator);}

	void simplify();
	int get_whole_part() const{return  numerator / denominator;}
	int get_numerator() const {return numerator;}
	int get_denominator() const {return denominator;}

	Fraction& operator= (const Fraction& other) = default;
	Fraction& operator= (Fraction&& other) = default;
	Fraction& operator += (const Fraction& other);
	Fraction& operator -= (const Fraction& other);
	Fraction& operator *= (const Fraction& other);
	Fraction& operator /= (const Fraction& other);

	friend const Fraction operator+ (const Fraction& a, const Fraction& b);
	friend const Fraction operator- (const Fraction& a, const Fraction& b);
	friend const Fraction operator* (const Fraction& a, const Fraction& b);
	friend const Fraction operator/ (const Fraction& a, const Fraction& b);
	friend std::ostream& operator << (std::ostream& os, const Fraction& q);
};
