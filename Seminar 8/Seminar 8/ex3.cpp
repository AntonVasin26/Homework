#include "Header.hpp"
#include "ex3.hpp"

namespace My_space
{
	void Fraction::simplify()
	{
		auto d = std::gcd(numerator, denominator);
		numerator /= d;
		denominator /= d;
	}

	Fraction const Fraction::get_fractional_part()
	{
		My_space::Fraction A(numerator - denominator * get_whole_part(), denominator);
		return A;
	}

	Fraction pow(const Fraction &f, int n)
	{
		Fraction f1;
		f1.numerator = std::pow(f.numerator, n);
		f1.denominator = std::pow(f.denominator, n);
		f1.simplify();
		return f1;
	}

	Fraction pow(const Fraction &f , double n)
	{
		if (abs(n - static_cast<int>(n)) < std::numeric_limits<double>::epsilon())
			return pow(f, static_cast<int>(n));
		if (f.numerator < 0 && abs(n - static_cast<int>(n)) > std::numeric_limits<double>::epsilon())
			throw My_space::Fractional_power_of_a_negative_number();
		double A = static_cast<double>(f.numerator) / static_cast<double>(f.denominator);
		A = std::pow(A, n);
		Fraction f1(A);
		return f1;
	}

	Fraction& Fraction::denom_plus(int n)
	{
		if (denominator > -n)
			denominator += n;
		else
			std::cout << "\nthe denominator is less than zero\n";
		simplify();
		return *this;
	}

	Fraction& Fraction::denom_minus(int n)
	{
		if (denominator > n)
			denominator -= n;
		else
			std::cout << "\nthe denominator is less than zero\n";
		simplify();
		return *this;
	}

	std::ostream& operator << (std::ostream& os, const Fraction& f)
	{
		os << f.numerator << '/' << f.denominator;
		return os;
	}

	std::istream& operator>>(std::istream& in, Fraction& f1)
	{
		char c;
		in >> f1.numerator;
		in >> c;
		in >> f1.denominator;
		f1.simplify();
		return in;

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
		if (other.numerator == 0)
			throw Division_by_zero();
		numerator *= other.denominator;
		denominator *= other.numerator;
		return *this;
	}

	Fraction operator + (const Fraction& a, const Fraction& b)
	{
		Fraction ans = a;
		ans += b;
		ans.simplify();
		return ans;
	}

	Fraction operator - (const Fraction& a, const Fraction& b)
	{
		Fraction ans = a;
		ans -= b;
		ans.simplify();
		return ans;
	}

	Fraction operator * (const Fraction& a, const Fraction& b)
	{
		Fraction ans = a;
		ans *= b;
		ans.simplify();
		return ans;
	}

	Fraction operator / (const Fraction& a, const Fraction& b)
	{
		Fraction ans = a;
		ans /= b;
		ans.simplify();
		return ans;
	}

}
void ex3()
{
	My_space::Fraction a(-1, 3);
	My_space::Fraction b(0, 1);
	My_space::Fraction c;
	try
	{
		c = a / b;
	}
	catch (My_space::Division_by_zero e)
	{
		std::cout << "\n\n\n" << __FILE__ << ";\n line: " << __LINE__ << "Division_by_zero find";
	}
	try
	{
		a /= b;
	}
	catch (My_space::Division_by_zero e)
	{
		std::cout << "\n\n\n" << __FILE__ << ";\n line: " << __LINE__ << "Division_by_zero find";
	}
	try
	{
		c = pow(a, 0.5);
	}
	catch (My_space::Fractional_power_of_a_negative_number e)
	{
		std::cout << "\n\n\n" << __FILE__ << ";\n line: " << __LINE__ << "; Fractional_power_of_a_negative_number find";
	}
}

