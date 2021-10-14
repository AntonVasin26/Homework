#include "Header.hpp"
#include "ex2.hpp"


void Fraction::simplify()
{
	auto d = std::gcd(numerator, denominator);
	numerator /= d;
	denominator /= d;
}

std::ostream& operator << (std::ostream& os, const Fraction& f)
{
	os << f.numerator << '/' << f.denominator << std::endl;
	return os;
}

Fraction& Fraction::operator += (const Fraction& other)
{
	numerator = numerator * other.denominator + denominator * other.numerator;
	denominator = denominator * other.denominator;
	return *this;
}

Fraction& Fraction::operator -= (const Fraction& other)
{
	numerator = numerator * other.denominator - denominator * other.numerator;
	denominator = denominator * other.denominator;
	return *this;
}

Fraction& Fraction::operator *= (const Fraction& other)
{
	numerator *= other.numerator;
	denominator *= other.denominator;
	return *this;
}

Fraction& Fraction::operator /= (const Fraction& other)
{
	numerator *= other.denominator;
	denominator *= other.numerator;
	return *this;
}

const Fraction operator + (const Fraction& a, const Fraction& b)
{
	Fraction ans = a;
	ans += b;
	if (a.simply && b.simply)
	{
		ans.simplify();
		ans.simply = false;
	}
	return ans;
}

const Fraction operator - (const Fraction& a, const Fraction& b)
{
	Fraction ans = a;
	ans -= b;
	if (a.simply && b.simply)
	{
		ans.simplify();
		ans.simply = false;
	}
	return ans;
}

const Fraction operator * (const Fraction& a, const Fraction& b)
{
	Fraction ans = a;
	ans *= b;
	if (a.simply && b.simply)
	{
		ans.simplify();
		ans.simply = false;
	} 
	return ans;
}

const Fraction operator / (const Fraction& a, const Fraction& b)
{
	Fraction ans = a;
	ans /= b;
	if (a.simply && b.simply)
	{
		ans.simplify();
		ans.simply = false;
	}
	return ans;
}

int main()
{
	Fraction a(1, 5);
	Fraction b(2, 5);
	double c = 23.5;
	b = c + b;
	std::cout << a;
	std::cout << b;
}