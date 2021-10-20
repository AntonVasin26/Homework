//#include "Header.hpp"
//#include "ex2.hpp"
//
//Fraction& Fraction::operator= (const Fraction& other)
//{
//	numerator = other.numerator;
//	denominator = other.denominator;
//	simply = other.simply;
//	return *this;
//}
//
//Fraction& Fraction::operator= (Fraction&& other)
//{
//	numerator = other.numerator;
//	other.numerator = 0;
//	denominator = other.denominator;
//	other.denominator = 1;
//	simply = other.simply;
//	other.simply = true;
//	return *this;
//}
//
//
//Fraction operator+(const Fraction& a, const Fraction& b)
//{
//	Fraction c;
//	if (a.simply && b.simply)
//	{
//		c.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
//		c.denominator = b.denominator * a.denominator;
//		c.simplify();
//	}
//	else
//	{
//		c.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
//		c.denominator = b.denominator * a.denominator;
//		c.simply = false;
//	}
//	return c;
//}
//
//Fraction operator-(const Fraction& a, const Fraction& b)
//{
//	Fraction c;
//	if (a.simply && b.simply)
//	{
//		c.numerator = (a.numerator * b.denominator) - (a.denominator * b.numerator);
//		c.denominator = b.denominator * a.denominator;
//		c.simplify();
//	}
//	else
//	{
//		c.numerator = (a.numerator * b.denominator) - (a.denominator * b.numerator);
//		c.denominator = b.denominator * a.denominator;
//	}
//	return c;
//}
//
//Fraction operator*(const Fraction& a, const Fraction& b)
//{
//	Fraction c;
//	if (a.simply && b.simply)
//	{
//		c.numerator = a.numerator * b.numerator;
//		c.denominator = a.denominator * b.denominator;
//		c.simplify();
//	}
//	else
//	{
//		c.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
//		c.denominator = b.denominator * a.denominator;
//	}
//	return c;
//}
//
//Fraction operator/(const Fraction& a, const Fraction& b)
//{
//	Fraction c;
//	if (a.simply && b.simply)
//	{
//		c.numerator = a.numerator * b.denominator;
//		c.denominator = a.denominator * b.numerator;
//		c.simplify();
//	}
//	else
//	{
//		c.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
//		c.denominator = b.denominator * a.denominator;
//	}
//	return c;
//}
//
//std::ostream& operator << (std::ostream& os, const Fraction& f)
//{
//	os << f.numerator << '/' << f.denominator << std::endl;
//	return os;