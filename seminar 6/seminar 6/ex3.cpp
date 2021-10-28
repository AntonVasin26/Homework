#include "Header.hpp"
#include "ex2.hpp"

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


int main()
{
	My_space::Fraction f1(1, 4);
	My_space::Fraction f2(2, 8);
	std::cout << f1 << '\n';
	std::cout << f2 << '\n';
	std::cout << (f1 == f2) << '\n';
	f2 = pow(f1, 1.5);
	std::cout << f2 << '\n';

	My_space::Fraction f3(1.5);
	std::cout << f3 << '\n';
	double f4 = 2.75;
	std::cout << f4 << '\n';
	My_space::Fraction f5(4.8);
	f5 += f4;
	f5 -= f4;
	f5 *= f4;
	f5 /= f4;
	f5 = f3 + f4;
	f5 = f3 - f4;
	f5 = f3 * f4;
	f5 = f3 / f4;
	f5 = f4 + f3;
	f5 = f4;

	My_space::Fraction f6(1, 2);
	My_space::Fraction f7(2, 3);
	My_space::Fraction f8(2, 4);
	f6 > f7;
	f6 < f7;
	f6 >= f8;
	f6 <= f8;
	++f6;
	--f7;
	f6.num_plus(1);
	f6.num_minus(1);

	std::cin >> f6;
}